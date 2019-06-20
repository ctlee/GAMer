/*
 * ***************************************************************************
 * This file is part of the GAMer software.
 * Copyright (C) 2016-2018
 * by Christopher Lee, John Moody, Rommie Amaro, J. Andrew McCammon,
 *    and Michael Holst
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 * ***************************************************************************
 */


/**
 * @file gamer.h
 * @brief Contains various global definitions for the overall project
 */

#pragma once

#include "gamer/tensor.h"

// The number of rings to use to compute local structure tensor
#define RINGS 1

/** @brief Blurring blobyness used in conversion from PDB/PQR to 3D volumes */
#define BLOBBYNESS        -0.2f

/** @brief Discretization rate of 3D volumes */
#define DIM_SCALE         1.99

/** @brief The minimal volumes (in voxels) of islands to be removed */
#define MIN_VOLUME        333333

#ifdef SINGLE
#define REAL float
#else
#define REAL double
#endif

using Vector = tensor<REAL,3,1>;
using d3Vector = tensor<double,3,1>;
using f3Vector = tensor<float,3,1>;
using i3Vector = tensor<int,3,1>;
using szt3Vector = tensor<std::size_t,3,1>;

/**
 * @brief      Convert 3D array indices to the index of a flat
 *             array.
 *
 * As a convention use the following loop structure to optimize
 * cache efficiency:
 * ~~~~~~~~~~~~~~~{.cpp}
 *  for (int k;...; k++){
 *    for (int j;...; j++){
 *      for (int i;...; i++){
 *  }}}
 * ~~~~~~~~~~~~~~~
 * In short, index i should occupy the inner most scope followed
 * by j then k.
 *
 * @param[in]  i     Value of the first index
 * @param[in]  j     Value of the second index
 * @param[in]  k     Value of the third index
 * @param[in]  dim   Dimensions of the 3D array
 *
 * @return     Index of flat array corresponding to indices in
 *             3D array.
 */
inline std::size_t Vect2Index(const std::size_t i, const std::size_t j, const std::size_t k, const szt3Vector& dim){
    return k*dim[0]*dim[1] + j*dim[0] + i;
}