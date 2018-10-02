# Geometry-preserving Adaptive MeshER

GAMer is a surface mesh improvement library developed to condition surface
meshes derived from noisy biological imaging data. Using Tetgen, GAMer can
generate tetrahedral meshes suitable for finite elements simulations of
reaction-diffusion systems among others. Currently this version of GAMer is
available only as a library, Blender addon, and python module. In the future,
we will reintroduce CLI programs for mesh processing.

# Build Status
[![Build Status](https://travis-ci.org/ctlee/gamer.svg?branch=master)](https://travis-ci.org/ctlee/gamer)

### Installing
Prebuilt binaries of the GAMer Blender-addon are available under
[releases](https://github.com/ctlee/gamer/releases). Download the corresponding
`.zip` for your platform and follow Blender's instructions to [install from file](https://docs.blender.org/manual/fi/dev/preferences/addons.html#header).

#### Prerequisites
To build the GAMer library you will need access to a working C++ compiler with full C++14 support.
If you wish to use build and use the GAMer Python extensions, you will
also need [SWIG > 3.0](http://www.swig.org/), access to a python intepreter,
and the corresponding python shared library (`python.so` or `python.dylib`).
In order to use the GAMer Blender addon you should also have a working
installation of Blender.

#### Building
The following instructions are to build the base GAMer library. If you wish to
additionally compile the Blender GAMer addon, GAMer documentation, or other
features please refer to the Additional Options section prior to building.

First, download a copy of the source from [releases](https://github.com/ctlee/gamer/releases) or clone the master branch.\
```bash
git clone https://github.com/ctlee/gamer.git
cd gamer
git submodule init
git submodule update
```

Linux and Mac:
```bash
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX:PATH=/usr -DBUILD_TESTS=on -DCMAKE_BUILD_TYPE=Release ..
make
```

For Windows, we support building using Microsoft Visual Studio (MSVS) through the use of CMake generators:
```bash
cmake -DBUILD_BLENDER=TRUE -G "Visual Studio 15 2017 Win64" ..
cmake --build build64 --config Release
```

#### Additional Options
To enable these options append the flags to your initial CMake function call
(e.g., `cmake -DBUILD_BLENDER=on ..`). These can be used in addition to the
standard [CMake flags](https://cmake.org/cmake/help/latest/manual/cmake.1.html).

* Build Python Extension: `-DBUILD_PYTHONEXT=ON`
* Build the Blender addon: `-DBUILD_BLENDER=ON`\
    This automatically builds the Python extension.
* Single Precision floating point numbers: `-DSINGLE=ON`
* Compile Tetgen Binary: `-DBUILD_TETGEN_BIN=ON`
* Test Cases: `-DBUILD_TESTS=ON`
    The test suite can be run using `make tests` or executing the output `./bin/objecttests`. Tests are organized using [GoogleTest](https://github.com/google/googletest) project.
* The GAMer documentation can be built if you have access to
[doxygen](http://www.doxygen.nl/) by running `make docs` with any build.

## Authors
**John Moody**\
Department of Mathematics\
University of California, San Diego

**[Christopher Lee](https://github.com/ctlee)**\
Department of Chemistry & Biochemistry\
University of California, San Diego

### Contributors to GAMer
* Zeyun Yu (UCSD) and Yuhui Cheng(UCSD)\
Development of GAMer v1. To cite use of GAMer v1, please cite the following
paper:\
Z. Yu, M. Holst, Y. Cheng, and J.A. McCammon, Feature-Preserving Adaptive Mesh Generation for Molecular Shape Modeling and Simulation. Journal of Molecular Graphics and Modeling, 26(8) (2008), pp. 1370-1380.

* Tom Bartol (Salk Institute) and Johan Hake\
Development of Blender GAMer addon.

See also the list of [contributors](https://github.com/ctlee/gamer/contributors) who participated in this project.

## External libraries bundled with GAMer
* GAMer uses [Tetgen](http://wias-berlin.de/software/tetgen/) to generate
tetrahedralizations.

* GAMer uses [Eigen](http://eigen.tuxfamily.org/index.php?title=Main_Page) to
compute eigenvalues/eigenvectors of the Local Structure Tensor.

* GAMer uses [casc](https://github.com/ctlee/casc) as the underlying simplicial
complex data structure.

* GAMer uses [GoogleTest](https://github.com/google/googletest) to handle testing.