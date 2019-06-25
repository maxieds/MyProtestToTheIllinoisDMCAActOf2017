// *************************************************
// *                                               *
// *  infograph.h                                  *
// *                                               *
// *  Interface for a parameterized graph class    *
// *                                               *
// *  Written 10 Nov 1998 by Jason Zych            *
// *    Comments added April 1999 by Jason Zych    *
// *                                               *
// *  Inspiration for this graph class drawn from  *
// *   the publicly posted interface of the LEDA   *
// *   library: http://www.mpi-sb.mpg.de/LEDA/     *
// *                                               *
// *  Directed flag added to constructor           *
// *    3 August 1999 by Jason Zych                *
// *************************************************

#ifndef _INFOGRAPH_H
#define _INFOGRAPH_H

#include "graph.h"
#include "array.h"

template <class Vtype, class Etype>
class InfoGraph : public Graph
{
public:

   // InfoGraph
   //    - default constructor
   //    - parameter : isDirectedFlag - sets whether graph is directed or not
   //    - initializes object to default values 
   InfoGraph(int isDirectedFlag = 1);


   // InsertVertex
   //    - parameters : vertValue - value to be attached to new vertex
   //    - return value : the new vertex
   //    - adds a new vertex to graph, assigns the vertex the value 
   //         vertValue, and returns the vertex 
   Vertex InsertVertex(Vtype vertValue);


   // InsertEdge
   //    - parameters : sourceVert - source vertex of new edge
   //                 : targetVert - target vertex of new edge
   //                 : edgeValue - value to be attached to new edge 
   //    - return value : the new edge
   //    - adds a new edge to the graph between the parameter vertices,
   //         assigns the edge the value edgeValue, and returns that edge
   Edge InsertEdge(Vertex sourceVert, Vertex targetVert, Etype edgeValue);


   // VertexInfo
   //    - parameters : infoVert - vertex whose value we want
   //    - return type : a vertex information value
   //    - returns the information variable stored in this vertex 
   Vtype VertexInfo(Vertex infoVert);


   // EdgeInfo 
   //    - parameters : infoEdge - edge whose value we want
   //    - return type : an edge information value
   //    - returns the information variable stored in this edge 
   Etype  EdgeInfo(Edge infoEdge);


   // VertexAssign
   //    - parameters : infoVert - vertex at which we will store info
   //                 : vertValue - information value for the vertex
   //    - stores the value vertValue at the vertex infoVert, writing
   //       over whatever information used to be at infoVert, if any  
   void VertexAssign(Vertex infoVert, Vtype vertValue);


   // EdgeAssign
   //    - parameters : infoEdge - edge at which we will store info
   //                 : edgeValue - information value for the edge
   //    - stores the value edgeValue at the edge infoEdge, writing  
   //       over whatever information used to be at infoEdge, if any
   void EdgeAssign(Edge infoEdge, Etype edgeValue);

private:

   Array<Vtype> vertexInfo;
   Array<Etype> edgeInfo; 

};

#endif
