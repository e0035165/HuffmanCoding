//
//  HuffNode.hpp
//  huffmanDataCompression
//
//  Created by Sart Way on 15/12/22.
//

#ifndef HuffNode_hpp
#define HuffNode_hpp

#include <stdio.h>
#include <vector>

class HuffNode
{
public:
    HuffNode();
    virtual bool isLeaf() = 0;
    virtual int wgt() = 0;
    ~HuffNode();
};

#endif /* HuffNode_hpp */
