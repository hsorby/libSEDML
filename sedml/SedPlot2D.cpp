/**
 * @file:   SedPlot2D.cpp
 * @brief:  Implementation of the SedPlot2D class
 * @author: Frank T. Bergmann
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSEDML.  Please visit http://sed-ml.org for more
 * information about SEDML, and the latest version of libSEDML.
 *
 * Copyright (c) 2013, Frank T. Bergmann  
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met: 
 * 
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer. 
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution. 
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ------------------------------------------------------------------------ -->
 */


#include <sedml/SedPlot2D.h>
#include <sedml/SedTypes.h>
#include <sbml/xml/XMLInputStream.h>


using namespace std;


LIBSEDML_CPP_NAMESPACE_BEGIN


/*
 * Creates a new SedPlot2D with the given level, version, and package version.
 */
SedPlot2D::SedPlot2D (unsigned int level, unsigned int version)
	: SedOutput(level, version)
	, mCurve (level, version)

{
	// set an SedNamespaces derived object of this package
	setSedNamespacesAndOwn(new SedNamespaces(level, version));

	// connect to child objects
	connectToChild();
}


/*
 * Creates a new SedPlot2D with the given SedNamespaces object.
 */
SedPlot2D::SedPlot2D (SedNamespaces* sedns)
	: SedOutput(sedns)
	, mCurve (sedns)

{
	// set the element namespace of this object
	setElementNamespace(sedns->getURI());

	// connect to child objects
	connectToChild();
}


/*
 * Copy constructor for SedPlot2D.
 */
SedPlot2D::SedPlot2D (const SedPlot2D& orig)
	: SedOutput(orig)
{
	if (&orig == NULL)
	{
		throw SedConstructorException("Null argument to copy constructor");
	}
	else
	{
		mCurve  = orig.mCurve;

		// connect to child objects
		connectToChild();
	}
}


/*
 * Assignment for SedPlot2D.
 */
SedPlot2D&
SedPlot2D::operator=(const SedPlot2D& rhs)
{
	if (&rhs == NULL)
	{
		throw SedConstructorException("Null argument to assignment");
	}
	else if (&rhs != this)
	{
		SedOutput::operator=(rhs);
		mCurve  = rhs.mCurve;

		// connect to child objects
		connectToChild();
	}
	return *this;
}


/*
 * Clone for SedPlot2D.
 */
SedPlot2D*
SedPlot2D::clone () const
{
	return new SedPlot2D(*this);
}


/*
 * Destructor for SedPlot2D.
 */
SedPlot2D::~SedPlot2D ()
{
}


/*
 * Returns the  "SedListOfCurves" in this SedPlot2D object.
 */
const SedListOfCurves*
SedPlot2D::getListOfCurves() const
{
	return &mCurve;
}


/*
 * Removes the nth Curve from the SedListOfCurves.
 */
SedCurve*
SedPlot2D::removeCurve(unsigned int n)
{
	return mCurve.remove(n);
}


/*
 * Removes the a Curve with given id from the SedListOfCurves.
 */
SedCurve*
SedPlot2D::removeCurve(const std::string& sid)
{
	return mCurve.remove(sid);
}


/*
 * Return the nth Curve in the SedListOfCurves within this SedPlot2D.
 */
SedCurve*
SedPlot2D::getCurve(unsigned int n)
{
	return mCurve.get(n);
}


/*
 * Return the nth Curve in the SedListOfCurves within this SedPlot2D.
 */
const SedCurve*
SedPlot2D::getCurve(unsigned int n) const
{
	return mCurve.get(n);
}


/*
 * Return a Curve from the SedListOfCurves by id.
 */
SedCurve*
SedPlot2D::getCurve(const std::string& sid)
{
	return mCurve.get(sid);
}


/*
 * Return a Curve from the SedListOfCurves by id.
 */
const SedCurve*
SedPlot2D::getCurve(const std::string& sid) const
{
	return mCurve.get(sid);
}


/**
 * Adds a copy the given "SedCurve" to this SedPlot2D.
 *
 * @param sc; the SedCurve object to add
 *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li LIBSEDML_OPERATION_SUCCESS
 * @li LIBSEDML_INVALID_ATTRIBUTE_VALUE
 */
int
SedPlot2D::addCurve(const SedCurve* sc)
{
	if(sc == NULL) return LIBSEDML_INVALID_ATTRIBUTE_VALUE;
	mCurve.append(sc);
	return LIBSEDML_OPERATION_SUCCESS;
}


/**
 * Get the number of SedCurve objects in this SedPlot2D.
 *
 * @return the number of SedCurve objects in this SedPlot2D
 */
unsigned int 
SedPlot2D::getNumCurves() const
{
	return mCurve.size();
}

/**
 * Creates a new SedCurve object, adds it to this SedPlot2Ds
 * SedPlot2D and returns the SedCurve object created. 
 *
 * @return a new SedCurve object instance
 *
 * @see addSedCurve(const SedCurve* sc)
 */
SedCurve* 
SedPlot2D::createCurve()
{
	SedCurve *temp = new SedCurve();
	if (temp != NULL) mCurve.appendAndOwn(temp);
	return temp;
}

/*
 * Returns the XML element name of this object
 */
const std::string&
SedPlot2D::getElementName () const
{
	static const string name = "plot2D";
	return name;
}


/**
 * return the SEDML object corresponding to next XMLToken.
 */
SedBase*
SedPlot2D::createObject(XMLInputStream& stream)
{
	SedBase* object = SedOutput::createObject(stream);

	const string& name   = stream.peek().getName();

	SedOutput::connectToChild();

	if (name == "listOfCurves")
	{
		object = &mCurve;
	}

	return object;
}


/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedPlot2D::connectToChild ()
{
	SedOutput::connectToChild();

	mCurve.connectToParent(this);
}


/*
 * Returns the libSEDML type code for this SEDML object.
 */
int
SedPlot2D::getTypeCode () const
{
	return SEDML_OUTPUT_PLOT2D;
}


/*
 * check if all the required attributes are set
 */
bool
SedPlot2D::hasRequiredAttributes () const
{
	bool allPresent = SedOutput::hasRequiredAttributes();

	return allPresent;
}


/*
 * check if all the required elements are set
 */
bool
SedPlot2D::hasRequiredElements () const
{
	bool allPresent = SedOutput::hasRequiredElements();

	return allPresent;
}


/** @cond doxygen-libsbml-internal */

/*
 * write contained elements
 */
void
SedPlot2D::writeElements (XMLOutputStream& stream) const
{
	SedOutput::writeElements(stream);
	if (getNumCurves() > 0)
	{
		mCurve.write(stream);
	}
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Accepts the given SedVisitor.
 */
bool
SedPlot2D::accept (SedVisitor& v) const
{
	return false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Sets the parent SedDocument.
 */
void
SedPlot2D::setSedDocument (SedDocument* d)
{
	SedOutput::setSedDocument(d);
}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Get the list of expected attributes for this element.
 */
void
SedPlot2D::addExpectedAttributes(ExpectedAttributes& attributes)
{
	SedOutput::addExpectedAttributes(attributes);

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Read values from the given XMLAttributes set into their specific fields.
 */
void
SedPlot2D::readAttributes (const XMLAttributes& attributes,
                             const ExpectedAttributes& expectedAttributes)
{
	SedOutput::readAttributes(attributes, expectedAttributes);

	bool assigned = false;

}


/** @endcond doxygen-libsbml-internal */


/** @cond doxygen-libsbml-internal */

/*
 * Write values of XMLAttributes to the output stream.
 */
	void
SedPlot2D::writeAttributes (XMLOutputStream& stream) const
{
	SedOutput::writeAttributes(stream);

}


/** @endcond doxygen-libsbml-internal */


/**
 * write comments
 */
LIBSEDML_EXTERN
SedPlot2D_t *
SedPlot2D_create(unsigned int level, unsigned int version)
{
	return new SedPlot2D(level, version);
}


/**
 * write comments
 */
LIBSEDML_EXTERN
void
SedPlot2D_free(SedPlot2D_t * spd)
{
	if (spd != NULL)
		delete spd;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
SedPlot2D_t *
SedPlot2D_clone(SedPlot2D_t * spd)
{
	if (spd != NULL)
	{
		return static_cast<SedPlot2D_t*>(spd->clone());
	}
	else
	{
		return NULL;
	}
}


LIBSEDML_EXTERN
int
SedPlot2D_addCurve(SedPlot2D_t * spd, SedCurve_t * sc)
{
	return  (spd != NULL) ? spd->addCurve(sc) : LIBSBML_INVALID_OBJECT;
}

LIBSEDML_EXTERN
SedCurve_t *
SedPlot2D_createCurve(SedPlot2D_t * spd)
{
	return  (spd != NULL) ? spd->createCurve() : NULL;
}

LIBSEDML_EXTERN
SedListOf_t *
SedPlot2D_getSedListOfCurves(SedPlot2D_t * spd)
{
	return  (spd != NULL) ? (SedListOf_t *)spd->getListOfCurves() : NULL;
}

LIBSEDML_EXTERN
SedCurve_t *
SedPlot2D_getCurve(SedPlot2D_t * spd, unsigned int n)
{
	return  (spd != NULL) ? spd->getCurve(n) : NULL;
}

LIBSEDML_EXTERN
SedCurve_t *
SedPlot2D_getCurveById(SedPlot2D_t * spd, const char * sid)
{
	return  (spd != NULL) ? spd->getCurve(sid) : NULL;
}

LIBSEDML_EXTERN
unsigned int
SedPlot2D_getNumCurves(SedPlot2D_t * spd)
{
	return  (spd != NULL) ? spd->getNumCurves() : SEDML_INT_MAX;
}

LIBSEDML_EXTERN
SedCurve_t *
SedPlot2D_removeCurve(SedPlot2D_t * spd, unsigned int n)
{
	return  (spd != NULL) ? spd->removeCurve(n) : NULL;
}

LIBSEDML_EXTERN
SedCurve_t *
SedPlot2D_removeCurveById(SedPlot2D_t * spd, const char * sid)
{
	return  (spd != NULL) ? spd->removeCurve(sid) : NULL;
}

/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedPlot2D_hasRequiredAttributes(SedPlot2D_t * spd)
{
	return (spd != NULL) ? static_cast<int>(spd->hasRequiredAttributes()) : 0;
}


/**
 * write comments
 */
LIBSEDML_EXTERN
int
SedPlot2D_hasRequiredElements(SedPlot2D_t * spd)
{
	return (spd != NULL) ? static_cast<int>(spd->hasRequiredElements()) : 0;
}




LIBSEDML_CPP_NAMESPACE_END


