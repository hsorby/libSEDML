/**
 * @file    libsedml-version.h
 * @brief   Define libSEDML version numbers for access from client software.
 * @author  Frank T. Bergmann
 *
 *<!---------------------------------------------------------------------------
 * This file is part of libSEDML.  Please visit http://sbml.org for more
 * information about SEDML, and the latest version of libSEDML.
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
 * in the file named "LICENSE.txt" included with this software distribution and
 * also available online as http://sbml.org/software/libsedml/license.html
 *------------------------------------------------------------------------- -->
 */

#ifndef LIBSEDML_VERSION_H
#define LIBSEDML_VERSION_H 

#include <sedml/common/extern.h>


/**
 * LIBSEDML_DOTTED_VERSION:
 *
 * A version string of the form "1.2.3".
 */
#define LIBSEDML_DOTTED_VERSION	"@PACKAGE_VERSION@"


/**
 * LIBSEDML_VERSION:
 *
 * The version as an integer: version 1.2.3 becomes 10203.  Since the major
 * number comes first, the overall number will always increase when a new
 * libSEDML is released, making it easy to use less-than and greater-than
 * comparisons when testing versions numbers.
 */
#define LIBSEDML_VERSION		@LIBSEDML_VERSION_NUMERIC@


/**
 * LIBSEDML_VERSION_STRING:
 *
 * The numeric version as a string: version 1.2.3 becomes "10203".
 */
#define LIBSEDML_VERSION_STRING	"@LIBSEDML_VERSION_NUMERIC@"


LIBSEDML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS

/**
 * Returns the version number of this copy of libSEDML as an integer.
 *
 * @return the libSEDML version as an integer; version 1.2.3 becomes 10203.
 */
LIBSEDML_EXTERN
int 
getLibSEDMLVersion ();


/**
 * Returns the version number of this copy of libSEDML as a string.
 *
 * @return the libSEDML version as a string; version 1.2.3 becomes
 * "1.2.3".
 *
 * @see getLibSEDMLVersionString()
 */
LIBSEDML_EXTERN
const char* 
getLibSEDMLDottedVersion ();


/**
 * Returns the version number of this copy of libSEDML as a string without
 * periods.
 *
 * @return the libSEDML version as a string: version 1.2.3 becomes "10203".
 *
 * @see getLibSEDMLDottedVersion()
 */
LIBSEDML_EXTERN
const char* 
getLibSEDMLVersionString ();


END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#endif  /* LIBSEDML_VERSION_H */
