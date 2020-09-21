/*
 *  \date Mar 16, 2018
 *  \author Magnar Bjørgve <magnar.bjorgve@uit.no> \n
 *          Hylleraas Centre for Quantum Molecular Sciences \n
 *          UiT - The Arctic University of Norway
 */
#pragma once

#include <pybind11/pybind11.h>

#include <MRCPP/trees/MWNode.h>
#include <MRCPP/trees/MWTree.h>
#include <MRCPP/trees/SerialTree.h>

template <int D, typename Base = mrcpp::SerialTree<D>>
class PySerialTree : public Base {
public:
    /* Inherit the constructors */
    using Base::Base;

    void allocRoots(mrcpp::MWTree<D> &tree) override { PYBIND11_OVERLOAD_PURE(void, Base, allocRoots, tree); }
    void allocChildren(mrcpp::MWNode<D> &parent) override { PYBIND11_OVERLOAD_PURE(void, Base, allocChildren, parent); }
    void allocGenChildren(mrcpp::MWNode<D> &parent) override { PYBIND11_OVERLOAD_PURE(void, Base, allocGenChildren, parent); } 

    void deallocNodes(int serialIx) override { PYBIND11_OVERLOAD_PURE(void, Base, deallocNodes, serialIx); }
    void deallocGenNodes(int serialIx) override { PYBIND11_OVERLOAD_PURE(void, Base, deallocGenNodes, serialIx); }
    void deallocGenNodeChunks() override { PYBIND11_OVERLOAD_PURE(void, Base, deallocGenNodeChunks); }
};
