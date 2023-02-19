//
//  HuffNode.cpp
//  huffmanDataCompression
//
//  Created by Sart Way on 15/12/22.
//

#include "HuffNode.hpp"

class HuffChar : public HuffNode
{
public:
    int weight;
    char Ch;
    HuffChar(char C, int size) : HuffNode()
    {
        this->Ch = C;
        this->weight = size;
    }
    ~HuffChar();
    
    bool isLeaf()
    {
        return true;
    }
    
    int wgt()
    {
        return weight;
    }
    
    
    
};

class PairNode : public HuffNode
{
public:
    HuffNode* ln;
    HuffNode* rn;
    int weight;
    PairNode(HuffNode* L, HuffNode* R) : HuffNode()
    {
        ln = L;
        rn = R;
        this->weight = L->wgt() + R->wgt();
    }
    bool isLeaf()
    {
        return false;
    }
    
    int wgt()
    {
        return weight;
    }
    
    ~PairNode();
    
    
};


class HuffTreeNode : public HuffNode{
public:
    HuffNode* current;
    HuffTreeNode* previous = nullptr;
    HuffTreeNode* next = nullptr;
    HuffTreeNode(HuffNode* curr)
    {
        this->current = curr;
    }
    
    HuffTreeNode(HuffChar* leaf)
    {
        this->current = leaf;
    }
    
    HuffTreeNode(PairNode* node)
    {
        this->current = node;
    }
    
    HuffTreeNode(HuffNode* curr, HuffNode* Prev, HuffNode* Next)
    {
        this->current = curr;
        HuffTreeNode* front = new HuffTreeNode(Prev);
        HuffTreeNode* back = new HuffTreeNode(Next);
        this->previous = front;
        this->next = back;
        
    }
    
    int wgt()
    {
        return current->wgt();
    }
    
    bool isLeaf()
    {
        return current->isLeaf();
    }
    
    
    
    
};
