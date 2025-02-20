#### Backgroun 
DREAM3D is an open source software for computational microstructure modeling and reconstruction. The software can be used specially for polycrystalline
microstructure generation, processing, characterization, manipulation, and many more. One of the special capabilities of this software is to generate statistically 
equivalent RVE of materials-microstructure. However, if there are multiphases in a single grains  or any other complexity exists in a grain, that is not
covered. For example, if the microstructure has lamellar grains, or, grains with twin regions, or any other intra-grain complexity then this software cannot
offer such functionalities. 

#### Objective:
Lets say, We would like introduce statistically equivalent microstructures  even inside each grain. For example, duplex, fully-lamellar, or grains with twins,
etc. To achieve this we need an efficient algorithm that is to be implemented as a filter of DREAM3D. 

#### Generating duplex or fully lamellar RVE:
The class or filter (GenerateLamellaeForDuplex) is an attempt to generate duplex or fully lamellar microstructures. To make statistically equivalent,
there are many tasks to be done. This filter is the first step to this total work. Approximately 70 different directional lamellae can be generated according
to the developed algorithm. This filter includes only 10 directional lamellae so far. Rest are to be included one by one.

#### How to use:
To use this filter, firstly, DREAM3D developer version will have to be installed. Then this filter will have to be put into the proper group. Corresponding 
documentation file will have to be updated and linked. Finally, the complete DREAM3D project will have be compiled/rebuilt. Once successful build is done, 
this filter will appear in the user interface of DREAM3D. So the filter can be used in any intended pipeline of DREAM3D. 


#### Results:
An example output is shown with two images. TiAl alloy microstructure (1000 grains) without lamellae (DuplexTiAl_1000grainsWithoutLamella.png), generated by DREAM3D will be used as input 
for this filter. After executing the filter, particular type of grains will have lamellar structures (DuplexTiAl_1000grains_withLamellae.png). 
