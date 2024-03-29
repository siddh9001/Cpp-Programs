#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct MinHeapNode{
    char data;
    unsigned freq;
    MinHeapNode *left,*right;
    
    MinHeapNode(char data, unsigned freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};

struct compare{
    bool operator()(MinHeapNode* l, MinHeapNode* r)
    {
        return l->freq > r->freq;
    }
    
};

void printCodes(MinHeapNode* root,string str)
{
    if(root == NULL)    
    return;
    
    if(root->data != '$')
        cout << root->data <<": "<< str << endl;
        
    printCodes(root->left,str + "0");
    printCodes(root->right,str + "1");
}

void huffManCodes(char data[],int freq[], int size)
{
    MinHeapNode *left , *right , *top;
    
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
    
    for(int i=0;i<size;i++)
        minHeap.push(new MinHeapNode(data[i],freq[i]));
        
    while(minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();
        
        right = minHeap.top();
        minHeap.pop();
    
        top = new MinHeapNode('$',left->freq + right->freq);
    
        top->left = left;
        top->right = right;
        
        minHeap.push(top);
    }
    
    printCodes(minHeap.top(),"");
}

int main()
{
     char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
 
    int size = sizeof(arr) / sizeof(arr[0]);
 
    huffManCodes(arr, freq, size);
 
    return 0;
}