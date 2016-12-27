#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<cstdio>
#include<queue>


using namespace std;


FILE *fp, *out;

struct node 
{
    string lSideOfProd;
    int nChild;
    vector<struct node *> childs;
};


class syntaxTree
{
       
    public:
        syntaxTree();      // constructor
        struct node *root;
        void buildTree();                
        void printTree();
};


string strip( string s)
{
    int i=0, j=s.size()-1;
    while( s[i] == ' ' || s[i] == '\n' )
        i++;
    while( s[j] == ' ' || s[j] == '\n' )
        j--;
    string ans;
    if(i<=j)
        ans = s.substr(i, j-i+1);    
    return ans;
}

string lSideOfProd(string s)
{
    int i=0;
    while( s[i] != ' ' && s[i] != ':')
        i++;
    return s.substr( 0, i);
}


syntaxTree::syntaxTree()
{
    root = NULL;
}


void syntaxTree::buildTree()
{
    char buff[150];
    vector< string > productions;
    while( fgets( buff, sizeof(buff), fp) != NULL )
    {
        string buff1 = string(buff);
        buff1 = strip( buff1 );
        if( buff1.size() > 0 )
        {
            productions.insert(productions.begin(), buff1);
        }
    }
    for( int i=0; i<productions.size(); i++)
        cout << productions[i] << endl;
    
    root = new struct node;
    
    
}

void syntaxTree::printTree()
{
    queue<struct node*> bfs;
    bfs.push(root);
    while(!bfs.empty())
    {
        struct node *temp = bfs.front();
        int nodes = 1;
        for(int i=0; i<temp->nChild; i++)
        {
            for(int j=0; j<nodes; j++)
            {
                fprintf(out, "%s (%d) ", bfs.front()->lSideOfProd, bfs.front()->nChild);
                bfs.pop();
            }
            fprintf(out, "\n");
            bfs.push(temp->childs[i]);
        }
    }
}


int main()
{
    string inFile;
    inFile = "treeInp.txt";
    fp = fopen(inFile.c_str(), "r");
    out = fopen("treeOut.txt", "w+");
    
    syntaxTree tree;
    tree.buildTree();
    fclose(out);
    fclose(fp);
    return 0;
}
