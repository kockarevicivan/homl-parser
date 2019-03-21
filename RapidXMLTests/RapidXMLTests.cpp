// RapidXMLTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <list>

#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include "rapidxml_iterators.hpp"
#include "rapidxml_print.hpp"

#include "GenericNode.h"
#include "ObjectNode.h"
#include "VideoNode.h"
#include "Video360Node.h"
#include "ImageNode.h"
#include "Image360Node.h"
#include "AudioNode.h"
#include "TextNode.h"
#include "BreakNode.h"
#include "InputNode.h"
#include "AnchorNode.h"
#include "DivisionNode.h"

using namespace std;
using namespace rapidxml;

void get_nodes(xml_node<>* node);
void print_list();

list<GenericNode> nodeList;

int main()
{
	file<char> input_file("C:\\Users\\Ivan\\Desktop\\Index.homl");

	xml_document<> doc;
	doc.parse<0>(input_file.data());

	xml_node<>* node = doc.first_node();
	get_nodes(node);

	print_list();

	return 0;
}

void print_list() {
	for (int i = 0; i < nodeList.size(); i++) {
		cout << i << endl;
	}
}

void get_nodes(xml_node<>* node) {

	if (!(node->first_node())) {
		return;
	}

	for (xml_node<>* n = node->first_node(); n; n = n->next_sibling()) {

		if (!strcmp(n->name(), "object")) {
			ObjectNode objectNode;
			nodeList.push_back(objectNode);
		}
		else if (!strcmp(n->name(), "video")) {
			VideoNode videoNode;
			nodeList.push_back(videoNode);
		}
		else if (!strcmp(n->name(), "video3d")) {
			Video360Node video360Node;
			nodeList.push_back(video360Node);
		}
		else if (!strcmp(n->name(), "img")) {
			ImageNode imageNode;
			nodeList.push_back(imageNode);
		}
		else if (!strcmp(n->name(), "img3d")) {
			Image360Node image360Node;
			nodeList.push_back(image360Node);
		}
		else if (!strcmp(n->name(), "audio")) {
			AudioNode audioNode;
			nodeList.push_back(audioNode);
		}
		else if (!strcmp(n->name(), "text")) {
			TextNode textNode;
			nodeList.push_back(textNode);
		}
		else if (!strcmp(n->name(), "br")) {
			BreakNode breakNode;
			nodeList.push_back(breakNode);
		}
		else if (!strcmp(n->name(), "input")) {
			InputNode inputNode;
			nodeList.push_back(inputNode);
		}
		else if (!strcmp(n->name(), "a")) {
			AnchorNode anchorNode;
			nodeList.push_back(anchorNode);
		}
		else if (!strcmp(n->name(), "div")) {
			DivisionNode divisionNode;
			nodeList.push_back(divisionNode);
		}

		get_nodes(n);
	}
}