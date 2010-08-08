//-----------------------------------------------
// Copyright 2010 Wellcome Trust Sanger Institute
// Written by Jared Simpson (js18@sanger.ac.uk)
// Released under the GPL
//-----------------------------------------------
//
// ScaffoldEdge - An edge in a scaffold graph. 
//
#ifndef SCAFFOLDEDGE_H
#define SCAFFOLDEDGE_H

#include "Edge.h"

class ScaffoldVertex;

enum ScaffoldEdgeType
{
    SET_DISTANCEEST,
    SET_REFERENCE,
    SET_INFERRED
};

class ScaffoldEdge
{
    public:

        ScaffoldEdge(ScaffoldVertex* pEnd, EdgeDir dir, EdgeComp comp,
                     int distance, double stdDev, int numPairs, ScaffoldEdgeType type);

        //
        void setTwin(ScaffoldEdge* pEdge);

        //
        VertexID getStartID() const;
        VertexID getEndID() const;
        ScaffoldVertex* getEnd() const;
        ScaffoldEdge* getTwin() const;
        EdgeDir getDir() const;
        EdgeComp getComp() const;
        int getDistance() const;
        double getStdDev() const;
        ScaffoldEdgeType getType() const;

        //
        friend std::ostream& operator<<(std::ostream& out, ScaffoldEdge& edge);

    private:
        ScaffoldVertex* m_pEnd;
        ScaffoldEdge* m_pTwin;
        EdgeData m_edgeData; // dir/comp member
        int m_distance;
        double m_stdDev;
        int m_numPairs;
        ScaffoldEdgeType m_type;

};

bool ScaffoldEdgePtrDistanceCompare(ScaffoldEdge* pXY, ScaffoldEdge* pXZ);


#endif
