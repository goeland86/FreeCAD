/***************************************************************************
 *   Copyright (c) 2019 WandererFan <wandererfan@gmail.com>                *
 *                                                                         *
 *   This file is part of the FreeCAD CAx development system.              *
 *                                                                         *
 *   This library is free software; you can redistribute it and/or         *
 *   modify it under the terms of the GNU Library General Public           *
 *   License as published by the Free Software Foundation; either          *
 *   version 2 of the License, or (at your option) any later version.      *
 *                                                                         *
 *   This library  is distributed in the hope that it will be useful,      *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU Library General Public License for more details.                  *
 *                                                                         *
 *   You should have received a copy of the GNU Library General Public     *
 *   License along with this library; see the file COPYING.LIB. If not,    *
 *   write to the Free Software Foundation, Inc., 59 Temple Place,         *
 *   Suite 330, Boston, MA  02111-1307, USA                                *
 *                                                                         *
 ***************************************************************************/

#ifndef TECHDRAW_COSMETICEXTENSION_H
#define TECHDRAW_COSMETICEXTENSION_H

#include <App/DocumentObject.h>
#include <App/DocumentObjectExtension.h>
#include <App/PropertyStandard.h>
#include <App/Material.h>

#include <Base/Vector3D.h>
#include <Base/Exception.h>

#include "PropertyCosmeticVertexList.h"
#include "PropertyCosmeticEdgeList.h"


namespace TechDraw {
class DrawViewPart;
class GeometryObject;

class TechDrawExport CosmeticExtension : public App::DocumentObjectExtension {
    EXTENSION_PROPERTY_HEADER(TechDraw::CosmeticObject);

public:
    CosmeticExtension();
    virtual ~CosmeticExtension();

    TechDraw::PropertyCosmeticVertexList CosmeticVertexes;
    TechDraw::PropertyCosmeticEdgeList   CosmeticEdges;

    virtual std::string     addCosmeticVertex(Base::Vector3d pos);
    virtual CosmeticVertex* getCosmeticVertexBySelection(std::string name) const;
    virtual CosmeticVertex* getCosmeticVertexBySelection(int i) const;
    virtual CosmeticVertex* getCosmeticVertex(std::string id) const;
    virtual bool            replaceCosmeticVertex(CosmeticVertex* newVertex);
    virtual void            removeCosmeticVertex(std::string tag);
    virtual void            removeCosmeticVertex(std::vector<std::string> delTags);

    virtual std::string     addCosmeticEdge(Base::Vector3d start, Base::Vector3d end);
    virtual std::string     addCosmeticEdge(TechDraw::BaseGeom* bg);
    virtual CosmeticEdge*   getCosmeticEdgeBySelection(std::string name) const;
    virtual CosmeticEdge*   getCosmeticEdgeBySelection(int i) const;
    virtual CosmeticEdge*   getCosmeticEdge(std::string id) const;
    virtual bool            replaceCosmeticEdge(CosmeticEdge* newEdge);
    virtual void            removeCosmeticEdge(std::string tag);
    virtual void            removeCosmeticEdge(std::vector<std::string> delTags);


    PyObject* getExtensionPyObject(void);

protected:
/*    virtual void extHandleChangedPropertyName(Base::XMLReader &reader, */
/*                                              const char* TypeName, */
/*                                              const char* PropName);*/

private:

};

typedef App::ExtensionPythonT<CosmeticExtension> CosmeticExtensionPython;

} //end namespace TechDraw

#endif //TECHDRAW_COSMETICEXTENSION_H