/*
 * ***************************************************************************
 * This file is part of the GAMer software.
 * Copyright (C) 2016-2019
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

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "gamer/TetMesh.h"

namespace py = pybind11;

void init_TetMesh(py::module& mod){
    // Bindings for TetMesh
    py::class_<TetMesh> TetMeshCls(mod, "TetMesh",
        R"delim(
            Python wrapper around a :cpp:type:`TetMesh`.
        )delim"
    );
    TetMeshCls.def(py::init<>(), "Default constructor.");

    /************************************
     *  INSERT/REMOVE
     ************************************/
    TetMeshCls.def("addVertex",
        py::overload_cast<const tetmesh::TetVertex&>(&TetMesh::add_vertex),
        py::arg("data"),
        R"delim(
            Add a vertex to the mesh without specifying the key.
        )delim"
    );


    TetMeshCls.def("insertVertex",
        py::overload_cast<const std::array<int, 1>&, const tetmesh::TetVertex&>(&TetMesh::insert<1>),
        py::arg("key"), py::arg("data") = tetmesh::TetVertex(),
        R"delim(
            Inserts a vertex and data based on key.

            Args:
                key (list): Array [1] of vertex key.
                data (:py:class:`Vertex`, optional): Vertex data.
        )delim"
    );


    TetMeshCls.def("insertEdge",
        py::overload_cast<const std::array<int, 2>&, const tetmesh::Edge&>(&TetMesh::insert<2>),
        py::arg("key"), py::arg("data") = tetmesh::Edge(),
        R"delim(
            Insert an edge into the mesh.

            Args:
                key (list): Array [2] of edge key.
                data (Edge): Edge data.
        )delim"
    );


    TetMeshCls.def("insertFace",
        py::overload_cast<const std::array<int, 3>&, const tetmesh::Face&>(&TetMesh::insert<3>),
        py::arg("key"), py::arg("data") = tetmesh::Face(),
        R"delim(
            Insert a face into the mesh.

            Args:
                key (list): Array [3] of face key.
                data (Face): Face data.
        )delim"
    );


    TetMeshCls.def("insertCell",
        py::overload_cast<const std::array<int, 4>&, const tetmesh::Cell&>(&TetMesh::insert<4>),
        py::arg("key"), py::arg("data") = tetmesh::Cell(),
        R"delim(
            Insert a face into the mesh.

            Args:
                key (list): Array [4] of cell key.
                data (Cell): Cell data.
        )delim"
    );


    TetMeshCls.def("removeVertex",
        py::overload_cast<const std::array<int, 1>&>(&TetMesh::remove<1>),
        py::arg("key"),
        R"delim(
            Remove a vertex from the mesh.

            Args:
                key (list): Array [1] of vertex key.

            Returns:
                removed (int): Number of simplices removed
        )delim"
    );


    TetMeshCls.def("removeVertex",
        py::overload_cast<TetMesh::SimplexID<1>>(&TetMesh::remove<1>),
        py::arg("key"),
        R"delim(
            Remove a vertex from the mesh.

            Args:
                key (:py:class:`VertexID`): SimplexID of vertex.

            Returns:
                removed (int): Number of simplices removed
        )delim"
    );


    TetMeshCls.def("removeEdge",
        py::overload_cast<const std::array<int, 2>&>(&TetMesh::remove<2>),
        py::arg("key"),
        R"delim(
            Remove an edge from the mesh.

            Args:
                key (list): Array [2] of edge key.

            Returns:
                removed (int): Number of simplices removed
        )delim"
    );


    TetMeshCls.def("removeEdge",
        py::overload_cast<TetMesh::SimplexID<2>>(&TetMesh::remove<2>),
        py::arg("key"),
        R"delim(
            Remove an edge from the mesh.

            Args:
                key (:py:class:`EdgeID`): SimplexID of edge.

            Returns:
                removed (int): Number of simplices removed
        )delim"
    );


    TetMeshCls.def("removeFace",
        py::overload_cast<const std::array<int, 3>&>(&TetMesh::remove<3>),
        py::arg("key"),
        R"delim(
            Remove a face from the mesh.

            Args:
                key (list): Array [3] of face key.

            Returns:
                removed (int): Number of simplices removed
        )delim"
    );


    TetMeshCls.def("removeFace",
        py::overload_cast<TetMesh::SimplexID<3>>(&TetMesh::remove<3>),
        py::arg("key"),
        R"delim(
            Remove a face from the mesh

            Args:
                key (:py:class:`FaceID`): SimplexID of face.

            Returns:
                removed (int): Number of simplices removed
        )delim"
    );


    TetMeshCls.def("removeCell",
        py::overload_cast<const std::array<int, 4>&>(&TetMesh::remove<4>),
        py::arg("key"),
        R"delim(
            Remove a cell from the mesh.

            Args:
                key (list): Array [3] of cell key.

            Returns:
                removed (int): Number of simplices removed
        )delim"
    );


    TetMeshCls.def("removeCell",
        py::overload_cast<TetMesh::SimplexID<4>>(&TetMesh::remove<4>),
        py::arg("key"),
        R"delim(
            Remove a cell from the mesh

            Args:
                key (:py:class:`CellID`): SimplexID of cell.

            Returns:
                removed (int): Number of simplices removed
        )delim"
    );


    /************************************
     * GET SIMPLEXID
     ************************************/
    // NOTE: these don't need py::return_value_policy::reference_internal
    // because they return pointers
    TetMeshCls.def("getVertex",
        py::overload_cast<const std::array<int, 1>&>(&TetMesh::get_simplex_up<1>, py::const_),
        R"delim(
            Get a simplex by key.

            Args:
                key (list): Array [1] of vertex key.

            Returns:
                SimplexID (:py:class:`VertexID`): The object.
        )delim"
    );

    TetMeshCls.def("getEdge",
        py::overload_cast<const std::array<int, 2>&>(&TetMesh::get_simplex_up<2>, py::const_),
        R"delim(
            Get a simplex by key.

            Args:
                key (list): Array [2] of edge key.

            Returns:
                SimplexID (:py:class:`EdgeID`): The object.
        )delim"
    );

    TetMeshCls.def("getFace",
        py::overload_cast<const std::array<int, 3>&>(&TetMesh::get_simplex_up<3>, py::const_),
        R"delim(
            Get a simplex by key.

            Args:
                key (list): Array [3] of vertex key.

            Returns:
                SimplexID (:py:class:`FaceID`): The object.
        )delim"
    );


    TetMeshCls.def("getCell",
        py::overload_cast<const std::array<int, 4>&>(&TetMesh::get_simplex_up<4>, py::const_),
        R"delim(
            Get a simplex by key.

            Args:
                key (list): Array [4] of vertex key.

            Returns:
                SimplexID (:py:class:`CellID`): The object.
        )delim"
    );


    TetMeshCls.def("getRoot",
        [](TetMesh &mesh) -> tetmesh::Global&{
            return mesh.get_simplex_up().data();
        },
        py::return_value_policy::reference_internal,
        R"delim(
            Get the global metadata.

            Returns:
                data (:py:class:`Global`): Global mesh metadata.
        )delim"
    );


    /************************************
     *  GET SIMPLEX NAMES
     ************************************/
    TetMeshCls.def("getName",
        py::overload_cast<TetMesh::SimplexID<1>>(&TetMesh::get_name<1>, py::const_),
        R"delim(
            Get the name of the vertex

            Args:
                SimplexID  (:py:class`VertexID`): VertexID to get the name of.

            Returns:
                key (list): Name of the vertex.
        )delim"
    );


    TetMeshCls.def("getName",
        py::overload_cast<TetMesh::SimplexID<2>>(&TetMesh::get_name<2>, py::const_),
        R"delim(
            Get the name of the edge

            Args:
                SimplexID  (:py:class`EdgeID`): EdgeID to get the name of.

            Returns:
                key (list): List of vertex indices which make up the edge.
        )delim"
    );


    TetMeshCls.def("getName",
        py::overload_cast<TetMesh::SimplexID<3>>(&TetMesh::get_name<3>, py::const_),
        R"delim(
            Get the name of the vertex

            Args:
                SimplexID  (:py:class`FaceID`): FaceID to get the name of.

            Returns:
                key (list): List of vertex indices which make up the face.
        )delim"
    );


    TetMeshCls.def("getName",
        py::overload_cast<TetMesh::SimplexID<4>>(&TetMesh::get_name<4>, py::const_),
        R"delim(
            Get the name of the vertex

            Args:
                SimplexID  (:py:class`CellID`): CellID to get the name of.

            Returns:
                key (list): List of vertex indices which make up the cell.
        )delim"
    );

    /************************************
     *  UTILITY
     ************************************/
    TetMeshCls.def_property_readonly("nVertices",
        py::overload_cast<>(&TetMesh::size<1>, py::const_),
        R"delim(
            Get the number of vertices.
        )delim"
    );


    TetMeshCls.def_property_readonly("nEdges",
        py::overload_cast<>(&TetMesh::size<2>, py::const_),
        R"delim(
            Get the number of edges.
        )delim"
    );


    TetMeshCls.def_property_readonly("nFaces",
        py::overload_cast<>(&TetMesh::size<3>, py::const_),
        R"delim(
            Get the number of faces.
        )delim"
    );


    TetMeshCls.def_property_readonly("nCells",
        py::overload_cast<>(&TetMesh::size<4>, py::const_),
        R"delim(
            Get the number of cells.
        )delim"
    );


    /************************************
     *  ITERATORS
     ************************************/
    TetMeshCls.def_property_readonly("vertexIDs",
        [](const TetMesh& m){
            auto it = m.get_level_id<1>();
            return py::make_iterator(it.begin(), it.end());
        },
        py::keep_alive<0, 1>(),
        R"delim(
            A convenience iterator over :py:class:`VertexID`.
        )delim"
    );


    TetMeshCls.def("getVertexIDIterator",
        [](const TetMesh& m){
            auto it = m.get_level_id<1>();
            return py::make_iterator(it.begin(), it.end());
        },
        py::keep_alive<0, 1>(), /* Essential: keep object alive while iterator exists */
        R"delim(
            Get an iterator over :py:class:`VertexID`.
        )delim"
    );


    TetMeshCls.def_property_readonly("edgeIDs",
        [](const TetMesh& m){
            auto it = m.get_level_id<2>();
            return py::make_iterator(it.begin(), it.end());
        },
        py::keep_alive<0, 1>(),
        R"delim(
            A convenience iterator over :py:class:`EdgeID`.
        )delim"
    );


    TetMeshCls.def("getEdgeIDIterator",
        [](const TetMesh& m){
            auto it = m.get_level_id<2>();
            return py::make_iterator(it.begin(), it.end());
        },
        py::keep_alive<0, 1>(), /* Essential: keep object alive while iterator exists */
        R"delim(
            Get an iterator over :py:class:`EdgeID`.
        )delim"
    );


    TetMeshCls.def_property_readonly("faceIDs",
        [](const TetMesh& m){
            auto it = m.get_level_id<3>();
            return py::make_iterator(it.begin(), it.end());
        },
        py::keep_alive<0, 1>(),
        R"delim(
            An convenience iterator over :py:class:`FaceID`.
        )delim"
    );


    TetMeshCls.def("getFaceIDIterator",
        [](const TetMesh& m){
            auto it = m.get_level_id<3>();
            return py::make_iterator(it.begin(), it.end());
        },
        py::keep_alive<0, 1>(), /* Essential: keep object alive while iterator exists */
        R"delim(
            Get an iterator over :py:class:`FaceID`.
        )delim"
    );


    TetMeshCls.def_property_readonly("cellIDs",
        [](const TetMesh& m){
            auto it = m.get_level_id<4>();
            return py::make_iterator(it.begin(), it.end());
        },
        py::keep_alive<0, 1>(),
        R"delim(
            An convenience iterator over :py:class:`CellID`.
        )delim"
    );


    TetMeshCls.def("getCellIDIterator",
        [](const TetMesh& m){
            auto it = m.get_level_id<4>();
            return py::make_iterator(it.begin(), it.end());
        },
        py::keep_alive<0, 1>(), /* Essential: keep object alive while iterator exists */
        R"delim(
            Get an iterator over :py:class:`CellID`.
        )delim"
    );


    /************************************
     *  ORIENTATION
     ************************************/
    TetMeshCls.def("init_orientation",
        py::overload_cast<TetMesh&>(&casc::init_orientation<TetMesh>),
        R"delim(
            Initialize mesh orientations.
        )delim"
    );


    TetMeshCls.def("check_orientation",
        py::overload_cast<TetMesh&>(&casc::check_orientation<TetMesh>),
        R"delim(
            Check consistency and assign Face orientations.

            :py:func:`TetMesh.init_orientation` must be called before this
            function can operate.
        )delim"
    );


    TetMeshCls.def("clear_orientation",
        py::overload_cast<TetMesh&>(&casc::clear_orientation<TetMesh>),
        R"delim(
            Clear orientation of all faces.
        )delim"
    );


    TetMeshCls.def("compute_orientation",
        py::overload_cast<TetMesh&>(&casc::compute_orientation<TetMesh>),
        R"delim(
            Compute orientations of the mesh.
        )delim"
    );
}