#pragma once
#include "stdafx.h"

#include "Body.h"
#include "SolidBody.h"
#include "Sphere.h"
#include "Parallelepiped.h"
#include "Cone.h"
#include "Cylinder.h"

bool ProcessCommand(std::string &commandLine, BodyPtrVector &bodiesVector);

void ShowBodies(BodyPtrVector &bodiesVector);

BodyPtr GetHeaviestBody(BodyPtrVector &bodiesVector);

BodyPtr GetLightestInWater(BodyPtrVector &bodiesVector);

void AddBody(std::string &commandLine, BodyPtrVector &bodiesVector);

std::string CutParamFromString(std::string &commandLine);

double GetMassInWater(BodyPtr const &body);

bool AddSphere(std::string &commandLine, BodyPtrVector &bodiesVector);

bool AddCone(std::string &commandLine, BodyPtrVector &bodiesVector);

bool AddParallelepiped(std::string &commandLine, BodyPtrVector &bodiesVector);

bool AddCylinder(std::string &commandLine, BodyPtrVector &bodiesVector);