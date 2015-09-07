//---------------------------------------------------------------------------

#include <vcl.h>
#include <assert.h>
#pragma hdrstop

#include "CMyList.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

//---------------------------------------------------------------------------

CMyListNode::CMyListNode( CMyListNode *pParent, AnsiString strName )
{
    m_pParent  = pParent;
    m_strName = strName;
}

CMyListNode::~CMyListNode()
{
// Nothing yet. No m_pChild - no party
}

CMyListNode *CMyListNode::GetParent()
{
    return m_pParent;
}

AnsiString CMyListNode::GetName()
{
    return m_strName;
}

//---------------------------------------------------------------------------

CMyList::CMyList( CMyListNode *pTail )
{
    m_pLastNode = pTail;
    m_nNodes    = 0;
}

CMyList::~CMyList()
{
    Clear();
}

CMyListNode *CMyList::GetLastNode()
{
    return m_pLastNode;
}

void CMyList::AddToEnd( AnsiString strName )
{
    m_pLastNode = new CMyListNode( m_pLastNode, strName );
    m_nNodes++;
}

void CMyList::DeleteLast()
{
    if( m_nNodes <= 0 ) return;

    assert( m_pLastNode != NULL );

    CMyListNode *pParent = m_pLastNode->GetParent();
    delete m_pLastNode;
    m_pLastNode = pParent;
    m_nNodes--;
}

void CMyList::Clear()
{
    while( m_nNodes > 0 )
    {
        DeleteLast();
    }
}

int CMyList::GetNodesCount()
{
    return m_nNodes;
}
//---------------------------------------------------------------------------

