#pragma once
#include "rapidxml.hpp"

using namespace rapidxml;

class GenericNode
{
	public:
		xml_node<>* parent;
		GenericNode() {};
		~GenericNode() {};
};