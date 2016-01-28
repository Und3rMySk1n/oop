#pragma once
#include "stdafx.h"

#include "Body.h"
#include "SolidBody.h"
#include "Sphere.h"
#include "Parallelepiped.h"
#include "Cone.h"
#include "Cylinder.h"

bool ProcessCommand(std::string const & command, std::istream & is);

void AddBody(std::istream & is, BodyPtrVector &bodiesVector);

BodyPtr CreateSphere(std::vector<double> &args);