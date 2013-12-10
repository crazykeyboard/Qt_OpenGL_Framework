// --------------------------------------------------------------------------
// gMini,
// a minimal Glut/OpenGL app to extend                              
//
// Copyright(C) 2007-2009                
// Tamy Boubekeur
//                                                                            
// All rights reserved.                                                       
//                                                                            
// This program is free software; you can redistribute it and/or modify       
// it under the terms of the GNU General Public License as published by       
// the Free Software Foundation; either version 2 of the License, or          
// (at your option) any later version.                                        
//                                                                            
// This program is distributed in the hope that it will be useful,            
// but WITHOUT ANY WARRANTY; without even the implied warranty of             
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              
// GNU General Public License (http://www.gnu.org/licenses/gpl.txt)           
// for more details.                                                          
//                                                                          
// --------------------------------------------------------------------------

#pragma once

#include <vector>
#include <string>
#include "Vertex.h"
#include "Triangle.h"
#include "Edge.h"
using namespace std;


class Mesh {
public:
    inline Mesh () {} 
    inline Mesh (const std::vector<Vertex> & v) : vertices (v) {}
    inline Mesh (const std::vector<Vertex> & v, 
                 const std::vector<Triangle> & t) : vertices (v), triangles (t)  {}
    inline Mesh (const Mesh & mesh) : vertices (mesh.vertices), triangles (mesh.triangles) {}
    inline virtual ~Mesh () {}
    const std::vector<Vertex> & getVertices () { return vertices; }
    const std::vector<Vertex> & getVertices () const { return vertices; }
    std::vector<Triangle> & getTriangles () { return triangles; }
    const std::vector<Triangle> & getTriangles () const { return triangles; }
    void clear ();
    void clearGeometry ();
    void clearTopology ();
    void recomputeSmoothVertexNormals (unsigned int weight);
    void computeTriangleNormals (std::vector<Vec3Df> & triangleNormals);  
    void collectOneRing (std::vector<std::vector<unsigned int> > & oneRing) const;
	bool openOFF(const string fileName, unsigned int normWeight = 0) ;
	inline int nVertices() {return (int)vertices.size() ;};
	inline int nTriangles() {return (int)triangles.size() ;} ;

  
private:
    std::vector<Vertex> vertices;
    std::vector<Triangle> triangles;
};

// Some Emacs-Hints -- please don't remove:
//
//  Local Variables:
//  mode:C++
//  tab-width:4
//  End:


//aid method,¸¨Öú»æÖÆ
inline void glVertexVec3Df (const Vec3Df & v) {
	glVertex3f (v[0], v[1], v[2]);
}
inline void glNormalVec3Df (const Vec3Df & n) {
	glNormal3f (n[0], n[1], n[2]);
}