#include "stdafx.h"
#include "scenenode.h"
#include "scenemanager.h"

//default constructor
CSceneNode::CSceneNode(
		CSceneManager *manager,
		const vector3d &position,
		const vector3d &rotation,
		const vector3d &scale,
		CSceneNode *parent) : 
	position(position), 
	rotation(rotation), 
	scale(scale), 
	parent(parent),
	manager(manager)
{
	transform.setPosition(position);
	if(!parent)
	{
		//no parent exists
		//so set parent to root scenenode
		parent = manager->getRootSceneNode();
	}
}

//copy constructor
//it aint easy
CSceneNode::CSceneNode(const CSceneNode &n) :
	transform(n.transform), position(n.position), rotation(n.rotation), scale(n.scale), parent(n.parent),
	manager(n.manager)
{
	//copy the list
	for(list<CSceneNode*>::iterator i = n.getChildren().begin(); i != n.getChildren().end(); i++)
	{
		children.push_back(*i);
	}
}

CSceneNode::~CSceneNode()
{
	//destructor
	children.clear();
}

void CSceneNode::render()
{
	//theres probably some opengl code that needs to be done here
	//update matrices
	transform.setPosition(position);
	transform.setRotationFromEuler(rotation); 
	if(parent)
	{
		transform = transform * parent->transform;
	}

	//do a depth first search to render
	for(list<CSceneNode*>::iterator i = children.begin(); i != children.end(); i++)
	{
		(*i)->render();
	}
}

void CSceneNode::remove()
{
	//if there is a parent, remove this as a child
	if(parent)
		parent->removeChild(this);
}

void CSceneNode::drop()
{
	//should only be used if created with a destructor, really
	delete this;
}

bool CSceneNode::removeChild(CSceneNode *child)
{
	//iterate through the list
	//and delete the child
	for(list<CSceneNode*>::iterator i = children.begin(); i != children.end(); i++)
	{
		if(*i == child)
		{
			child->setParent(0);
			i = children.erase(i);
			return true;
		}
	}
	return false;
}

void CSceneNode::addChild(CSceneNode *child)
{
	if(child->parent)
	{
		//make sure to remove this as a child
		parent->removeChild(child);
	}
	child->setParent(this);
	children.push_back(child);
}


std::list<CSceneNode*> CSceneNode::getChildren() const
{
	//self explanitory
	return children;
}