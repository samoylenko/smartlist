//---------------------------------------------------------------------------

#ifndef CMyListH
#define CMyListH

class CMyListNode
{
public:
    CMyListNode *m_pParent;
    AnsiString  m_strName;

    CMyListNode *GetParent();
    AnsiString GetName();

    CMyListNode( CMyListNode *pParent = NULL, AnsiString strName = "<empty>" );
    ~CMyListNode();
};

//---------------------------------------------------------------------------

class CMyList
{
public:
    CMyListNode *m_pLastNode;
    int          m_nNodes;

    CMyListNode *GetLastNode();
    void AddToEnd( AnsiString strName = "<empty>" );
    void DeleteLast();
    void Clear();
    int GetNodesCount();

    CMyList( CMyListNode *pTail = NULL );
    ~CMyList();
};
//---------------------------------------------------------------------------

#endif
