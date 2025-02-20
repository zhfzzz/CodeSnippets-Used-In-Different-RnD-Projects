/*
 * This is a filter, developed for integrating with DREAM3D, for generating lamellar grains from globular grains. 
*/

#pragma once

#include "SIMPLib/SIMPLib.h"
#include "SIMPLib/Common/SIMPLibSetGetMacros.h"
#include "SIMPLib/Filtering/AbstractFilter.h"

#include "Generic/GenericDLLExport.h"
/**
 * @brief The GenerateLamellaeForDuplex class. This filter will generate lamellar colonies 
 * with fixed width (e.g. 4 or 5 pixels/voxels) inside some pre-specified grains 
 */
class Generic_EXPORT GenerateLamellaeForDuplex : public AbstractFilter
{
  Q_OBJECT
	PYB11_CREATE_BINDINGS(GenerateLamellaeForDuplex SUPERCLASS AbstractFilter)
    PYB11_PROPERTY(DataArrayPath FeatureIdsArrayPath READ getFeatureIdsArrayPath WRITE setFeatureIdsArrayPath)
    PYB11_PROPERTY(DataArrayPath CellPhasesArrayPath READ getCellPhasesArrayPath WRITE setCellPhasesArrayPath)
    // PYB11_PROPERTY(DataArrayPath FeaturePhasesArrayPath READ getFeaturePhasesArrayPath WRITE setFeaturePhasesArrayPath)
    //  FeatureRect is FeatureCorners
    PYB11_PROPERTY(DataArrayPath FeatureRectArrayPath READ getFeatureRectArrayPath WRITE setFeatureRectArrayPath)

    PYB11_PROPERTY(DataArrayPath EulerAnglesArrayPath READ getEulerAnglesArrayPath WRITE setEulerAnglesArrayPath)
    PYB11_PROPERTY(DataArrayPath AvgEulerAnglesArrayPath READ getAvgEulerAnglesArrayPath WRITE setAvgEulerAnglesArrayPath)

  
  public:
    SIMPL_SHARED_POINTERS(GenerateLamellaeForDuplex)
    SIMPL_FILTER_NEW_MACRO(GenerateLamellaeForDuplex)
    SIMPL_TYPE_MACRO_SUPER(GenerateLamellaeForDuplex, AbstractFilter)

    ~GenerateLamellaeForDuplex() override;

	SIMPL_FILTER_PARAMETER(DataArrayPath, FeatureIdsArrayPath)
	Q_PROPERTY(DataArrayPath FeatureIdsArrayPath READ getFeatureIdsArrayPath WRITE setFeatureIdsArrayPath)

	SIMPL_FILTER_PARAMETER(DataArrayPath, CellPhasesArrayPath)
	Q_PROPERTY(DataArrayPath CellPhasesArrayPath READ getCellPhasesArrayPath WRITE setCellPhasesArrayPath)
    /*
	SIMPL_FILTER_PARAMETER(DataArrayPath, FeaturePhasesArrayPath)
	Q_PROPERTY(DataArrayPath FeaturePhasesArrayPath READ getFeaturePhasesArrayPath WRITE setFeaturePhasesArrayPath)
	*/
	SIMPL_FILTER_PARAMETER(DataArrayPath, FeatureRectArrayPath)
    Q_PROPERTY(DataArrayPath FeatureRectArrayPath READ getFeatureRectArrayPath WRITE setFeatureRectArrayPath)

	SIMPL_FILTER_PARAMETER(DataArrayPath, EulerAnglesArrayPath)
    Q_PROPERTY(DataArrayPath EulerAnglesArrayPath READ getEulerAnglesArrayPath WRITE setEulerAnglesArrayPath)

    SIMPL_FILTER_PARAMETER(DataArrayPath, AvgEulerAnglesArrayPath)
    Q_PROPERTY(DataArrayPath AvgEulerAnglesArrayPath READ getAvgEulerAnglesArrayPath WRITE setAvgEulerAnglesArrayPath)
    
    /**
     * @brief getCompiledLibraryName Reimplemented from @see AbstractFilter class
     */
    const QString getCompiledLibraryName() const override;

    /**
     * @brief getBrandingString Returns the branding string for the filter, which is a tag
     * used to denote the filter's association with specific plugins
     * @return Branding string
    */
    const QString getBrandingString() const override;

    /**
     * @brief getFilterVersion Returns a version string for this filter. Default
     * value is an empty string.
     * @return
     */
    const QString getFilterVersion() const override;

    /**
     * @brief newFilterInstance Reimplemented from @see AbstractFilter class
     */
    AbstractFilter::Pointer newFilterInstance(bool copyFilterParameters) const override;

    /**
     * @brief getGroupName Reimplemented from @see AbstractFilter class
     */
    const QString getGroupName() const override;

    /**
     * @brief getSubGroupName Reimplemented from @see AbstractFilter class
     */
    const QString getSubGroupName() const override;

    /**
     * @brief getUuid Return the unique identifier for this filter.
     * @return A QUuid object.
     */
    const QUuid getUuid() override;
  
    /**
     * @brief getHumanLabel Reimplemented from @see AbstractFilter class
     */
    const QString getHumanLabel() const override;

    /**
     * @brief setupFilterParameters Reimplemented from @see AbstractFilter class
     */
    void setupFilterParameters() override;

	/**
   * @brief readFilterParameters Reimplemented from @see AbstractFilter class
   */
  void readFilterParameters(AbstractFilterParametersReader* reader, int index) override;

  /**
     * @brief execute Reimplemented from @see AbstractFilter class
     */
    void execute() override;

    /**
    * @brief preflight Reimplemented from @see AbstractFilter class
    */
    void preflight() override;

  signals:
    /**
     * @brief updateFilterParameters Emitted when the Filter requests all the latest Filter parameters
     * be pushed from a user-facing control (such as a widget)
     * @param filter Filter instance pointer 
     */
    void updateFilterParameters(AbstractFilter* filter);

    /**
     * @brief parametersChanged Emitted when any Filter parameter is changed internally
     */
    void parametersChanged();

    /**
     * @brief preflightAboutToExecute Emitted just before calling dataCheck()
     */
    void preflightAboutToExecute();

    /**
     * @brief preflightExecuted Emitted just after calling dataCheck()
     */
    void preflightExecuted();

  protected:
    GenerateLamellaeForDuplex();

    /**
    * @brief dataCheck Checks for the appropriate parameter values and availability of arrays
    */
    void dataCheck();

    /**
    * @brief Initializes all the private instance variables.
    */
    void initialize();
	
	void generate_lamellaeX();

    /**
     * @brief sub2ind Helper Method.  Computes index from matrix coordinates
     * @param tDims
     * @param x
     * @param y
     * @param z
     * @return
     */
    size_t sub2ind(QVector<size_t> tDims, size_t x, size_t y, size_t z) const;
	//XY plane borabor 45degree te lamellae generation korar decision, true hole different than current phase
	bool lamellarDecisionXYplane(int x) const;
    

	  
  private:
	DEFINE_DATAARRAY_VARIABLE(int32_t, FeatureIds)
    DEFINE_DATAARRAY_VARIABLE(int32_t, CellPhases)
    // DEFINE_DATAARRAY_VARIABLE(int32_t, FeaturePhases)
    DEFINE_DATAARRAY_VARIABLE(size_t, FeatureRect)

    DEFINE_DATAARRAY_VARIABLE(float, EulerAngles)
    DEFINE_DATAARRAY_VARIABLE(float, AvgEulerAngles)
  
  public:
    /* Rule of 5: All special member functions should be defined if any are defined.
    * https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#c21-if-you-define-or-delete-any-default-operation-define-or-delete-them-all
    */
    GenerateLamellaeForDuplex(const GenerateLamellaeForDuplex&) = delete;             // Copy Constructor Not Implemented
    GenerateLamellaeForDuplex& operator=(const GenerateLamellaeForDuplex&) = delete;  // Copy Assignment Not Implemented
    GenerateLamellaeForDuplex(GenerateLamellaeForDuplex&&) = delete;                  // Move Constructor Not Implemented
    GenerateLamellaeForDuplex& operator=(GenerateLamellaeForDuplex&&) = delete;       // Move Assignment Not Implemented

};

