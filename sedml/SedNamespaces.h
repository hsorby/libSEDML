/**
 * @file    SedNamespaces.h
 * @brief   SedNamespaces class to store level/version and namespace 
 * @author  Sarah Keating
 * 
 * <!--------------------------------------------------------------------------
 * This file is part of libSed.  Please visit http://sbml.org for more
 * information about Sed, and the latest version of libSed.
 *
 * Copyright (C) 2009-2013 jointly by the following organizations: 
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EBML-EBI), Hinxton, UK
 *  
 * Copyright (C) 2006-2008 by the California Institute of Technology,
 *     Pasadena, CA, USA 
 *  
 * Copyright (C) 2002-2005 jointly by the following organizations: 
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. Japan Science and Technology Agency, Japan
 * 
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as http://sbml.org/software/libsbml/license.html
 * ------------------------------------------------------------------------ -->
 *
 * @class SedNamespaces
 * @ingroup Core
 * @brief Class to store Sed level, version and namespace information.
 *
 * @htmlinclude not-sbml-warning.html
 *
 * There are differences in the definitions of components between different
 * Sed Levels, as well as Versions within Levels.  For example, the
 * "sboTerm" attribute was not introduced until Level&nbsp;2
 * Version&nbsp;2, and then only on certain component classes; the Sed
 * Level&nbsp;2 Version&nbsp;3 specification moved the "sboTerm" attribute
 * to the SBase class, thereby allowing nearly all components to have SBO
 * annotations.  As a result of differences such as those, libSed needs to
 * track the Sed Level and Version of every object created.
 * 
 * The purpose of the SedNamespaces object class is to make it easier to
 * communicate Sed Level and Version data between libSed constructors and
 * other methods.  The SedNamespaces object class tracks 3-tuples
 * (triples) consisting of Sed Level, Version, and the corresponding Sed
 * XML namespace.
 *
 * The plural name (SedNamespaces) is not a mistake, because in Sed
 * Level&nbsp;3, objects may have extensions added by Level&nbsp;3 packages
 * used by a given model and therefore may have multiple namespaces
 * associated with them; however, until the introduction of Sed
 * Level&nbsp;3, the SedNamespaces object only records one Sed
 * Level/Version/namespace combination at a time.  Most constructors for
 * Sed objects in libSed take a SedNamespaces object as an argument,
 * thereby allowing the constructor to produce the proper combination of
 * attributes and other internal data structures for the given Sed Level
 * and Version.
 */

#ifndef SedNamespaces_h
#define SedNamespaces_h

#include <sbml/xml/XMLNamespaces.h>
#include <sedml/common/common.h>
#include <sedml/common/sedmlfwd.h>

#ifdef __cplusplus
namespace LIBSEDML_CPP_NAMESPACE {
  const unsigned int SEDML_DEFAULT_LEVEL   = 1;
  const unsigned int SEDML_DEFAULT_VERSION = 1;
  const char* const SEDML_XMLNS_L1   = "http://sed-ml.org/";  
}
#else
static const unsigned int SEDML_DEFAULT_LEVEL   = 1;
static const unsigned int SEDML_DEFAULT_VERSION = 1;
static const char* const SEDML_XMLNS_L1   = "http://sed-ml.org/";
#endif

#ifdef __cplusplus

#include <string>
#include <stdexcept>

LIBSEDML_CPP_NAMESPACE_BEGIN

class LIBSEDML_EXTERN SedNamespaces
{
public:

  /**
   * Creates a new SedNamespaces object corresponding to the given Sed
   * @p level and @p version.
   *
   * SedNamespaces objects are used in libSed to communicate Sed Level
   * and Version data between constructors and other methods.  The
   * SedNamespaces object class tracks 3-tuples (triples) consisting of
   * Sed Level, Version, and the corresponding Sed XML namespace.  Most
   * constructors for Sed objects in libSed take a SedNamespaces object
   * as an argument, thereby allowing the constructor to produce the proper
   * combination of attributes and other internal data structures for the
   * given Sed Level and Version.
   *
   * The plural name (SedNamespaces) is not a mistake, because in Sed
   * Level&nbsp;3, objects may have extensions added by Level&nbsp;3
   * packages used by a given model and therefore may have multiple
   * namespaces associated with them; however, until the introduction of
   * Sed Level&nbsp;3, the SedNamespaces object only records one Sed
   * Level/Version/namespace combination at a time.  Most constructors for
   * Sed objects in libSed take a SedNamespaces object as an argument,
   * thereby allowing the constructor to produce the proper combination of
   * attributes and other internal data structures for the given Sed Level
   * and Version.
   *
   * @param level the Sed level
   * @param version the Sed version
   * 
   * @if notcpp @htmlinclude warn-default-args-in-docs.html @endif@~
   */
  SedNamespaces(unsigned int level = SEDML_DEFAULT_LEVEL, 
                 unsigned int version = SEDML_DEFAULT_VERSION);

  /**
   * Destroys this SedNamespaces object.
   */
  virtual ~SedNamespaces();

  
  /**
   * Copy constructor; creates a copy of a SedNamespaces.
   * 
   * @param orig the SedNamespaces instance to copy.
   *
   * @throws @if python ValueError @else SedConstructorException @endif@~
   * Thrown if the argument @p orig is @c NULL.
   */
  SedNamespaces(const SedNamespaces& orig);


  /**
   * Assignment operator for SedNamespaces.
   *
   * @throws @if python ValueError @else SedConstructorException @endif@~
   * Thrown if the argument @p rhs is @c NULL.
   */
  SedNamespaces& operator=(const SedNamespaces& rhs);


  /**
   * Creates and returns a deep copy of this SedNamespaces.
   * 
   * @return a (deep) copy of this SedNamespaces.
   */
  virtual SedNamespaces* clone () const;


  /**
   * Returns a string representing the Sed XML namespace for the 
   * given @p level and @p version of Sed.
   *
   * @param level the Sed level
   * @param version the Sed version
   *
   * @return a string representing the Sed namespace that reflects the
   * Sed Level and Version specified.
   *
   * @if notclike @note Because this is a @em static method, the
   * non-C++ language interfaces for libSed will contain two variants.  One
   * will be a static method on the class (i.e., SedNamespaces), and the
   * other will be a standalone top-level function with the name
   * SedNamespaces_getSedNamespaceURI(). They are functionally
   * identical. @endif@~
   */
  static std::string getSedNamespaceURI(unsigned int level,
                                         unsigned int version);
  
  /**
   * Returns a list of all supported SedNamespaces in this version of 
   * libsbml. 
   * 
   * @return a list with supported Sed namespaces. 
   *
   * @if notclike @note Because this is a @em static method, the
   * non-C++ language interfaces for libSed will contain two variants.  One
   * will be a static method on the class (i.e., SedNamespaces), and the
   * other will be a standalone top-level function with the name
   * SedNamespaces_getSupportedNamespaces(). They are functionally
   * identical. @endif@~
   */
  static const List* getSupportedNamespaces();


  /**
   * Returns a string representing the Sed XML namespace of this
   * object.
   *
   * @return a string representing the Sed namespace that reflects the
   * Sed Level and Version of this object.
   */
  virtual std::string getURI() const;

  
  /**
   * Get the Sed Level of this SedNamespaces object.
   *
   * @return the Sed Level of this SedNamespaces object.
   */
  unsigned int getLevel();


  /**
   * Get the Sed Level of this SedNamespaces object.
   *
   * @return the Sed Level of this SedNamespaces object.
   */
  unsigned int getLevel() const;


  /**
   * Get the Sed Version of this SedNamespaces object.
   *
   * @return the Sed Version of this SedNamespaces object.
   */
  unsigned int getVersion();


  /**
   * Get the Sed Version of this SedNamespaces object.
   *
   * @return the Sed Version of this SedNamespaces object.
   */
  unsigned int getVersion() const;


  /**
   * Get the XML namespaces list for this SedNamespaces object.
   * 
   * The plural is not a mistake, because in Sed Level&nbsp;3, objects may
   * have extensions added by Level&nbsp;3 packages used by a given model,
   * and therefore there may be multiple XML namespaces involved too.
   * However, until the introduction of Sed Level&nbsp;3, the
   * SedNamespaces object only records one Sed Level/Version/namespace
   * combination at a time, and so this method will also only return
   * a list of one item.
   *
   * @return the XML namespaces of this SedNamespaces object.
   */
  XMLNamespaces * getNamespaces();


  /**
   * Get the XML namespaces list for this SedNamespaces object.
   * 
   * The plural is not a mistake, because in Sed Level&nbsp;3, objects may
   * have extensions added by Level&nbsp;3 packages used by a given model,
   * and therefore there may be multiple XML namespaces involved too.
   * However, until the introduction of Sed Level&nbsp;3, the
   * SedNamespaces object only records one Sed Level/Version/namespace
   * combination at a time, and so this method will also only return
   * a list of one item.
   *
   * @return the XML namespaces of this SedNamespaces object.
   */
  const XMLNamespaces * getNamespaces() const;


  /**
   * Add the given XML namespaces list to the set of namespaces within this
   * SedNamespaces object.
   *
   * The following code gives an example of how one could add the XHTML
   * namespace to the list of namespaces recorded by the top-level
   * <code>&lt;sbml&gt;</code> element of a model.  It gives the new
   * namespace a prefix of <code>html</code>.  @if clike
   * @verbatim
SedDocument *sd;
try 
{
    sd = new SedDocument(3, 1);
} 
catch (SedConstructorException e)
{
    // Here, have code to handle a truly exceptional situation. Candidate
    // causes include invalid combinations of Sed Level and Version
    // (impossible if hardwired as given here), running out of memory, and
    // unknown system exceptions.
}

SedNamespaces sn = sd->getNamespaces();
if (sn != NULL)
{
    sn->add("http://www.w3.org/1999/xhtml", "html");
}
else
{
    // Handle another truly exceptional situation.
}
@endverbatim
   * @endif@if java
@verbatim
SedDocument sd;
try 
{
    sd = new SedDocument(3, 1);
} 
catch (SedConstructorException e)
{
    // Here, have code to handle a truly exceptional situation. Candidate
    // causes include invalid combinations of Sed Level and Version
    // (impossible if hardwired as given here), running out of memory, and
    // unknown system exceptions.
}

SedNamespaces sn = sd.getNamespaces();
if (sn != null)
{
    sn.add("http://www.w3.org/1999/xhtml", "html");
}
else
{
    // Handle another truly exceptional situation.
 }
@endverbatim
   * @endif@if python
@verbatim
sbmlDoc = None
try:
  sbmlDoc = SedDocument(3, 1)
except ValueError:
  # Do something to handle exceptional situation.  Candidate
  # causes include invalid combinations of Sed Level and Version
  # (impossible if hardwired as given here), running out of memory, and
  # unknown system exceptions.

namespaces = sbmlDoc.getNamespaces()
if namespaces == None:
  # Do something to handle case of no namespaces.

status = namespaces.add("http://www.w3.org/1999/xhtml", "html")
if status != LIBSEDML_OPERATION_SUCCESS:
  # Do something to handle failure.
@endverbatim
   * @endif@if csharp
@verbatim
SedDocument sd = null;
try
{
    sd = new SedDocument(3, 1);
}
catch (SedConstructorException e)
{
    // Here, have code to handle a truly exceptional situation.
    // Candidate causes include invalid combinations of Sed
    // Level and Version (impossible if hardwired as given here),
    // running out of memory, and unknown system exceptions.
}

XMLNamespaces sn = sd.getNamespaces();
if (sn != null)
{
    sn.add("http://www.w3.org/1999/xhtml", "html");            
}
else
{
    // Handle another truly exceptional situation.
}
@endverbatim
   * @endif@~
   *
   * @param xmlns the XML namespaces to be added.
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif@~ The possible values
   * returned by this function are:
   * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_SUCCESS LIBSEDML_OPERATION_SUCCESS @endlink
   * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_FAILED LIBSEDML_OPERATION_FAILED @endlink
   * @li @link OperationReturnValues_t#LIBSEDML_INVALID_OBJECT LIBSEDML_INVALID_OBJECT @endlink
   */
  int addNamespaces(const XMLNamespaces * xmlns);


  /**
   * Add an XML namespace (a pair of URI and prefix) to the set of namespaces
   * within this SedNamespaces object.
   * 
   * @param uri    the XML namespace to be added.
   * @param prefix the prefix of the namespace to be added.
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif@~ The possible values
   * returned by this function are:
   * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_SUCCESS LIBSEDML_OPERATION_SUCCESS @endlink
   * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_FAILED LIBSEDML_OPERATION_FAILED @endlink
   * @li @link OperationReturnValues_t#LIBSEDML_INVALID_OBJECT LIBSEDML_INVALID_OBJECT @endlink
   */
  int addNamespace(const std::string& uri, const std::string &prefix);


  /**
   * Removes an XML namespace from the set of namespaces within this 
   * SedNamespaces object.
   * 
   * @param uri    the XML namespace to be added.
   *
   * @return integer value indicating success/failure of the
   * function.  @if clike The value is drawn from the
   * enumeration #OperationReturnValues_t. @endif@~ The possible values
   * returned by this function are:
   * @li @link OperationReturnValues_t#LIBSEDML_OPERATION_SUCCESS LIBSEDML_OPERATION_SUCCESS @endlink
   * @li @link OperationReturnValues_t#LIBSEDML_INDEX_EXCEEDS_SIZE LIBSEDML_INDEX_EXCEEDS_SIZE @endlink
   */
  int removeNamespace(const std::string& uri);


  /**
   * Predicate returning @c true if the given
   * URL is one of Sed XML namespaces.
   *
   * @param uri the URI of namespace
   *
   * @return @c true if the "uri" is one of Sed namespaces, @c false otherwise.
   *
   * @if notclike @note Because this is a @em static method, the
   * non-C++ language interfaces for libSed will contain two variants.  One
   * will be a static method on the class (i.e., SedNamespaces), and the
   * other will be a standalone top-level function with the name
   * SedNamespaces_isSedNamespace(). They are functionally
   * identical. @endif@~
   */
  static bool isSedNamespace(const std::string& uri);


  /**
   * Predicate returning @c true if the given
   * set of namespaces represent a valid set
   *
   * @return @c true if the set of namespaces is valid, @c false otherwise.
   */
  bool isValidCombination();


  /** @cond doxygen-libsbml-internal */
  void setLevel(unsigned int level);


  void setVersion(unsigned int version);


  void setNamespaces(XMLNamespaces * xmlns);
  /** @endcond */

	
protected:  
  /** @cond doxygen-libsbml-internal */

  void initSedNamespace();

  unsigned int    mLevel;
  unsigned int    mVersion;
  XMLNamespaces * mNamespaces;

  /** @endcond */
};

LIBSEDML_CPP_NAMESPACE_END

#endif  /* __cplusplus */


#ifndef SWIG

LIBSEDML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS

/* ----------------------------------------------------------------------------
 * See the .cpp file for the documentation of the following functions.
 * --------------------------------------------------------------------------*/

LIBSEDML_EXTERN
SedNamespaces_t *
SedNamespaces_create(unsigned int level, unsigned int version);


LIBSEDML_EXTERN
unsigned int
SedNamespaces_getLevel(SedNamespaces_t *sbmlns);


LIBSEDML_EXTERN
unsigned int
SedNamespaces_getVersion(SedNamespaces_t *sbmlns);


LIBSEDML_EXTERN
XMLNamespaces_t *
SedNamespaces_getNamespaces(SedNamespaces_t *sbmlns);


LIBSEDML_EXTERN
char *
SedNamespaces_getSedNamespaceURI(unsigned int level, unsigned int version);


LIBSEDML_EXTERN
int
SedNamespaces_addNamespaces(SedNamespaces_t *sbmlns,
                             const XMLNamespaces_t * xmlns);


LIBSEDML_EXTERN
SedNamespaces_t **
SedNamespaces_getSupportedNamespaces(int *length);

END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#endif  /* !SWIG */
#endif  /* SedNamespaces_h */
