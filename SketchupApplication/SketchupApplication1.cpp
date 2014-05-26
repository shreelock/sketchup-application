// SketchupApplication.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <slapi/slapi.h>
#include <slapi/geometry.h>
#include <slapi/initialize.h>
#include <slapi/model/model.h>
#include <slapi/model/entities.h>
#include <slapi/model/face.h>
#include <slapi/model/edge.h>
#include <slapi/model/vertex.h>
#include <slapi/model/material.h>
#include <slapi/color.h>
#include <vector>
#include <slapi/model/image.h>
#include <iostream>
#include <slapi/unicodestring.h>
#include <fstream>

using namespace std;
int main() {

	// Always initialize the API before using it
	SUInitialize();
	// Create an empty model
	SUModelRef model = SU_INVALID;
	

	SUResult res = SUModelCreate(&model);
	// It's best to always check the return code from each SU function call.
	// Only showing this check once to keep this example short.
	if (res != SU_ERROR_NONE)
	return 1;


	// Get the entity container of the model
	SUEntitiesRef entities = SU_INVALID;
	SUModelGetEntities(model, &entities);
	
	
	// Create the face
	SUFaceRef face1 = SU_INVALID;
	SUPoint3D vertices1[4] = {	
							{5,5,0},
							{5,10,0},
							{10,10,0},
							{10,5,0}
							};
	SUFaceCreateSimple(&face1, vertices1,4);// &outer_loop1);
	
	SUFaceRef face2 = SU_INVALID;
	SUPoint3D vertices2[4] = {	
							{0,0,0},
							{0,15,0},
							{15,15,0},
							{15,0,0}
							};
	SUFaceCreateSimple(&face2, vertices2,4);// &outer_loop2);

	SUFaceRef face3 = SU_INVALID;
	SUPoint3D vertices3[4] = {	
							{25,25,0},
							{25,30,0},
							{30,30,0},
							{30,25,0}
							};
	SUFaceCreateSimple(&face3, vertices3,4);// &outer_loop1);
	
	SUFaceRef face4 = SU_INVALID;
	SUPoint3D vertices4[4] = {	
							{20,20,0},
							{20,35,0},
							{35,35,0},
							{35,20,0}
							};
	SUFaceCreateSimple(&face4, vertices4,4);// &outer_loop2);
	
	// Add the faces to the entities
	SUEntitiesAddFaces(entities, 1, &face1);
	SUEntitiesAddFaces(entities, 1, &face2);
	SUEntitiesAddFaces(entities, 1, &face3);
	SUEntitiesAddFaces(entities, 1, &face4);
	
	
	std::cout<<"\nPheww.. Continued without Errors :P\n";
	// Save the in-memory model to a file
	SUModelSaveToFileWithVersion(model, "MODEL24_Loops.skp",SUModelVersion_SU2013);
	// Must release the model or there will be memory leaks
	SUModelRelease(&model);
	// Always terminate the API when done using it
	SUTerminate();
	getchar();
	return 0;
}


