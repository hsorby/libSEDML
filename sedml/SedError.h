/**
 * @file    SedError.h
 * @brief   Represents Sed errors and other diagnostics
 * @author  Michael Hucka
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
 * @class SedError
 * @ingroup Core
 * @brief Representation of errors, warnings and other diagnostics
 *
 * @htmlinclude not-sbml-warning.html
 *
 * When a libSed operation on Sed content results in an error, or when
 * there is something wrong with the Sed content, the problems are
 * reported as SedError objects.  These are generally stored in an
 * SedErrorLog object; this log object, in turn, is kept in the
 * SedDocument object containing the Sed content.  Applications can
 * obtain the list of logged errors using SedDocument::getErrorLog() and
 * then use the methods provided by SedErrorLog to access individual
 * SedError objects.  (Note that despite the word "error" in the name,
 * SedError objects are used to represent not only "true" errors, but also
 * warnings and some informational diagnostics.  The name is a historical
 * hold-over from early versions of libSed, in which the object really was
 * only used to report errors.)
 *
 * @if clike
 * Each SedError object instance has an identification number that
 * identifies the nature of the problem.  This "error id" number will be up
 * to five digits long, and it will be listed in one of two enumerations:
 * <a class="el" href="#SedErrorCode_t"> SedErrorCode_t</a> (described <a
 * class="el" href="#SedErrorCode_t"> below</a>) or @link
 * XMLError::XMLErrorCode_t XMLErrorCode_t @endlink (described in the
 * documentation for the class XMLError).  The former enumeration contains
 * all the Sed validation rule numbers listed in the appendices of the
 * Sed specification documents, as well as some additional
 * libSed-specific error codes.
 * @endif@if java
 * Each SedError object instance has an identification number that
 * identifies the nature of the problem.  This "error id" number will be up
 * to five digits long, and it will come from one of two sets of static
 * integer constants defined in the interface class <code><a
 * href="libsbmlConstants.html"> libsbmlConstants</a></code>: either the
 * Sed error identifiers <a class="el" href="#SedErrorCode_t"> (described
 * below)</a> or the XML error identifiers (described in the documentation
 * for the class <code><a href="XMLError.html"> XMLError</a></code>).  The
 * former set of constants includes all the Sed validation rule numbers
 * listed in the appendices of the Sed specification documents, as well as
 * some additional libSed-specific error codes.
 * @endif@if python
 * Each SedError object instance has an identification number that
 * identifies the nature of the problem.  This "error id" number will be up
 * to five digits long, and it will come from one
 * of two sets of static integer constants defined in
 * the interface class @link libsbml libsbml@endlink: either the Sed
 * error identifiers <a
 * class="el" href="#SedErrorCode_t"> (described below)</a> or the XML
 * error identifiers (described in the documentation for the class XMLError).
 * The former set of constants
 * includes all the Sed validation rule numbers listed in the appendices
 * of the Sed specification documents, as well as some additional
 * libSed-specific error codes.
 * @endif@~
 * 
 * Error codes are useful mainly for software.  For human readers,
 * SedError also includes text messages that describe the nature of a
 * given problem.  The messages can be accessed using
 * SedError::getShortMessage() and SedError::getMessage().  The former
 * provides a brief one-line description of the issue, while
 * SedError::getMessage() provides a more detailed text, including (if
 * appropriate) references to sections of the Sed specifications where
 * relevant topics are discussed.  These text strings are suitable for
 * displaying to human users.
 *
 * @if clike
 * An SedError object also contains a category code; its value may be
 * retrieved using the method SedError::getCategory().  Category values
 * are drawn from the enumeration <a class="el"
 * href="#SedErrorCategory_t">SedErrorCategory_t</a> described below.
 * Categories are used to partition errors into distinct conceptual groups.
 * This is principally used by the libSed validation system to group
 * classes of validation checks.  For example, 
 * @link SedErrorCategory_t#LIBSEDML_CAT_IDENTIFIER_CONSISTENCY LIBSEDML_CAT_IDENTIFIER_CONSISTENCY@endlink
 * is the category for tests that check identifier consistency;
 * @link SedErrorCategory_t#LIBSEDML_CAT_MATHML_CONSISTENCY LIBSEDML_CAT_MATHML_CONSISTENCY@endlink
 * is the category for MathML consistency checking; and
 * so on.
 * @endif@if java
 * An SedError object also contains a category code; its value may be
 * retrieved using the method SedError::getCategory().  Category values
 * are drawn from a set of static integer constants
 * defined in <code><a href="libsbmlConstants.html">libsbmlConstants</a></code>,
 * and having names beginning with the characters
 * <code>LIBSEDML_CAT_</code>.  The list of possible codes is described in a
 * separate section below.  Categories are used to partition errors into
 * distinct conceptual groups.  This is principally used by the libSed
 * validation system to group classes of validation checks.  For example,
 * @link SedErrorCategory_t#LIBSEDML_CAT_IDENTIFIER_CONSISTENCY LIBSEDML_CAT_IDENTIFIER_CONSISTENCY@endlink
 * is the category for tests that check identifier consistency;
 * @link SedErrorCategory_t#LIBSEDML_CAT_MATHML_CONSISTENCY LIBSEDML_CAT_MATHML_CONSISTENCY@endlink
 * is the category for MathML consistency checking; and
 * so on.
 * @endif@if python
 * An SedError object also contains a category code; its value may be
 * retrieved using the method SedError::getCategory().  Category values
 * are drawn from a set of static integer constants
 * defined in @link libsbml libsbml@endlink and having names beginning with the characters
 * <code>LIBSEDML_CAT_</code>.  The list of possible codes is described in a
 * separate section below.  Categories are used to partition errors into
 * distinct conceptual groups.  This is principally used by the libSed
 * validation system to group classes of validation checks.  For example,
 * @link SedErrorCategory_t#LIBSEDML_CAT_IDENTIFIER_CONSISTENCY LIBSEDML_CAT_IDENTIFIER_CONSISTENCY@endlink
 * is the category for tests that check identifier consistency;
 * @link SedErrorCategory_t#LIBSEDML_CAT_MATHML_CONSISTENCY LIBSEDML_CAT_MATHML_CONSISTENCY@endlink
 * is the category for MathML consistency checking; and
 * so on.
 * @endif@~
 *
 * In addition, SedError also has a severity code.  Its value may be
 * retrieved using the method SedError::getSeverity().  The possible
 * severity values are the same as those reported by @if clike XMLError.@endif@if python XMLError.@endif@if java <code><a href="XMLError.html">XMLError</a></code>.@endif@~ 
 * Severity levels currently range from informational
 * (@link XMLErrorSeverity_t#LIBSEDML_SEV_INFO LIBSEDML_SEV_INFO@endlink)
 * to fatal errors
 * (@link XMLErrorSeverity_t#LIBSEDML_SEV_FATAL LIBSEDML_SEV_FATAL@endlink).
 * They can be
 * used by an application to evaluate how serious a given problem
 * is. 
 *
 * Finally, SedError records the line and column near where the problem
 * occurred in the Sed content.  The values may be retrieved using the
 * methods SedError::getLine() and SedError::getColumn().  We say "near",
 * because a lot of factors affect how accurate the line/column information
 * ultimately is.  For example, different XML parsers have different
 * conventions for which line and column number they report for a
 * particular problem (which makes a difference when a problem involves an
 * opening XML tag on one line and a closing tag on another line).  In some
 * situations, some parsers report invalid line and/or column numbers
 * altogether.  If this occurs, libSed sets the line and/or column number
 * in the SedError object to the the value of the maximum unsigned long
 * integer representable on the platform where libSed is running.  (This
 * is equal to the constant named <code>ULONG_MAX</code> in C and C++.)
 * The probability that a true line or column number in an Sed model would
 * equal this value is vanishingly small; thus, if an application
 * encounters these values in an XMLError object, it can assume no valid
 * line/column number could be provided by libSed in that situation.
 *
 * @if clike
 * <h3><a class="anchor" name="SedErrorCode_t">SedErrorCode_t</a></h3>
 *
 * SedErrorCode_t is an enumeration of all Sed-level error, warning and
 * informational diagnostic codes.  Every SedError object has an error
 * code value that can be either a value from this enumeration, or a value
 * from the @link XMLError::XMLErrorCode_t XMLErrorCode_t @endlink
 * enumeration (see the documentation for XMLError).  The latter values
 * apply when the error or warning signifies a basic XML issue rather than
 * an Sed issue per se.  The values of SedErrorCode_t are distinguished
 * from those of @link XMLError::XMLErrorCode_t XMLErrorCode_t @endlink by
 * being numbered 10000 and higher, while the XML layer's codes are 9999 and
 * lower.  The method SedError::getErrorId() returns the error code of a
 * given SedError object instance.
 * 
 * The following is a table of the symbolic names of SedErrorCode_t values
 * and the meaning of each code.  In this table, the right-hand columns
 * titled "L1V1", "L1V2", etc. refer to Levels and Versions of the Sed
 * specifications, and the entries in each column refer to whether the
 * severity of the condition in that particular Level+Version of Sed.
 * The codes stand for the following:
 * 
 * @endif@if java <h3><a class="anchor" 
 * name="SedErrorCode_t">Error codes associated with SedError objects</a></h3>
 *
 * The error and warning codes returned by libSed are listed in the table
 * below.  The method SedError::getErrorId() returns the error code of a
 * given SedError object instance.  In the libSed Java language
 * interface, these error identifiers are currently
 * implemented as static integer constants defined in the interface class
 * <code><a href="libsbmlConstants.html">libsbmlConstants</a></code>.  This
 * is admittedly not an ideal approach from the standpoint of modern Java
 * programming, but it was necessary to work around the lack of
 * enumerations in Java prior to JDK 1.5.  Future versions of libSed may
 * use a proper Java enumeration type to define the error identifiers.
 * 
 * In this table, the right-hand columns titled "L1V1", "L1V2", etc. refer
 * to Levels and Versions of the Sed specifications, and the entries in
 * each column refer to whether the severity of the condition in that
 * particular Level+Version of Sed.  The codes stand for the following:
 *
 * @endif@if python <h3><a class="anchor" 
 * name="SedErrorCode_t">Error codes associated with SedError objects</a></h3>
 *
 * The error and warning codes returned by libSed are listed in the table
 * below.  The method SedError::getErrorId() returns the error code of a
 * given SedError object instance.  In the libSed Python language
 * interface, these error identifiers are currently
 * implemented as static integer constants defined in the interface class
 * @link libsbml libsbml@endlink. 
 * 
 * In this table, the right-hand columns titled "L1V1", "L1V2", etc. refer
 * to Levels and Versions of the Sed specifications, and the entries in
 * each column refer to whether the severity of the condition in that
 * particular Level+Version of Sed.  The codes stand for the following:
 *
 * @endif@~
 *
 * <table cellspacing="1" cellpadding="2" border="0" class="normal-font">
 * <tr><td class="s-na">N</td><td>= Not applicable</td></tr>
 * <tr><td class="s-info">I</td><td>= Informational</td></tr>
 * <tr><td class="s-warning">W</td><td>= Warning</td></tr>
 * <tr><td class="s-error">E</td><td>= Error</td></tr>
 * <tr><td class="s-fatal">F</td><td>= Fatal</td></tr>
 * </table>
 *
 * The text shown in the "Meaning" is the text returned by the
 * SedError::getShortMessage() method on a given SedError object.  A
 * longer and (hopefully) clearer explanation of the issue is returned by
 * SedError::getMessage().
 *
 * @htmlinclude sbmlerror-table.html
 * 
 * @if clike <h3><a class="anchor" name="SedErrorCategory_t">SedErrorCategory_t</a></h3>
 *
 * SedErrorCategory_t is an enumeration of category codes for SedError
 * diagnostics.  The category can be retrieved from an SedError object
 * using the method SedError::getCategory().  These enumeration values are
 * distinct from (and in addition to) the @link
 * XMLError::XMLErrorCategory_t XMLErrorCategory_t @endlink codes used by
 * the parent XMLError object.  User programs receiving an SedError object
 * can use this distinction to check whether the error represents a
 * low-level XML problem or an Sed problem.
 *
 * The following table lists each possible value and a brief description of
 * its meaning.
 * 
 * @endif@if python <h3><a class="anchor" name="SedErrorCategory_t">Category codes associated with SedError objects</a></h3>
 *
 * As discussed above, each SedError object contains a value for a
 * category identifier, describing the type of issue that the SedError
 * object represents.  The category can be retrieved from an SedError
 * object using the method SedError::getCategory().  The following table
 * lists each possible value and a brief description of its meaning.
 *
 * As is the case with the error codes, in the libSed Python language
 * interface, the category identifiers are currently implemented as static
 * integer constants defined in the interface class
 * @link libsbml libsbml@endlink. 
 *
 * The following table lists each possible value and a brief description of
 * its meaning.
 * 
 * @endif@if java <h3><a class="anchor"
 * name="SedErrorCategory_t">Category codes associated with SedError objects</a></h3>
 * 
 * As discussed above, each SedError object contains a value for a
 * category identifier, describing the type of issue that the SedError
 * object represents.  The category can be retrieved from an SedError
 * object using the method SedError::getCategory().  The following table
 * lists each possible value and a brief description of its meaning.
 * 
 * As is the case with the error codes, in the libSed Java language
 * interface, the category identifiers are currently implemented as static
 * integer constants defined in the interface class
 * {@link libsbmlConstants}.
 *
 * The following table lists each possible value and a brief description of
 * its meaning.
 * 
 * @endif@if csharp <h3><a class="anchor"
 * name="SedErrorCategory_t">Category codes associated with SedError objects</a></h3>
 * 
 * As discussed above, each SedError object contains a value for a
 * category identifier, describing the type of issue that the SedError
 * object represents.  The category can be retrieved from an SedError
 * object using the method SedError::getCategory().  The following table
 * lists each possible value and a brief description of its meaning.
 * 
 * As is the case with the error codes, in the libSed C# language
 * interface, the category identifiers are currently implemented as static
 * integer constants defined in the interface class
 * {@link libsbmlcs.libsbml}.
 *
 * The following table lists each possible value and a brief description of
 * its meaning.
 * 
 * @endif@~
 * 
 * <center>
 * <table width="90%" cellspacing="1" cellpadding="4" border="0"  class="text-table normal-font alt-row-colors">
 *  <tr style="background: lightgray" class="normal-font">
 *      <th>Enumerator</td>
 *      <th>Meaning</td>
 *  </tr>
 * <tr><td>@link XMLErrorCategory_t#LIBSEDML_CAT_SEDML LIBSEDML_CAT_SEDML@endlink</td><td>General error not falling into
 * another category below.</td></tr> 
 * <tr><td>@link XMLErrorCategory_t#LIBSEDML_CAT_SEDML_L1_COMPAT LIBSEDML_CAT_SEDML_L1_COMPAT@endlink</td><td>Category of errors
 * that can only occur during attempted translation from one Level/Version
 * of Sed to another.  This particular category applies to errors
 * encountered while trying to convert a model from Sed Level&nbsp;2 to Sed
 * Level&nbsp;1.</td></tr> 
 * <tr><td>@link XMLErrorCategory_t#LIBSEDML_CAT_SEDML_L2V1_COMPAT LIBSEDML_CAT_SEDML_L2V1_COMPAT@endlink</td><td>Category of errors
 * that can only occur during attempted translation from one Level/Version
 * of Sed to another.  This particular category applies to errors
 * encountered while trying to convert a model to Sed Level&nbsp;2
 * Version&nbsp;1.</td></tr> 
 * <tr><td>@link XMLErrorCategory_t#LIBSEDML_CAT_SEDML_L2V2_COMPAT LIBSEDML_CAT_SEDML_L2V2_COMPAT@endlink</td><td>Category of errors
 * that can only occur during attempted translation from one Level/Version
 * of Sed to another.  This particular category applies to errors
 * encountered while trying to convert a model to Sed Level&nbsp;2
 * Version&nbsp;2.</td></tr> 
 * <tr><td>@link XMLErrorCategory_t#LIBSEDML_CAT_GENERAL_CONSISTENCY LIBSEDML_CAT_GENERAL_CONSISTENCY@endlink</td><td>Category of
 * errors that can occur while validating general Sed constructs.  With
 * respect to the Sed specification, these concern failures in applying
 * the validation rules numbered 2xxxx in the Level&nbsp;2 Versions&nbsp;2&ndash;4
 * and Level&nbsp;3 Version&nbsp;1 specifications.</td></tr>
 * <tr><td>@link XMLErrorCategory_t#LIBSEDML_CAT_IDENTIFIER_CONSISTENCY LIBSEDML_CAT_IDENTIFIER_CONSISTENCY@endlink</td><td>Category of
 * errors that can occur while validating symbol identifiers in a model.
 * With respect to the Sed specification, these concern failures in
 * applying the validation rules numbered 103xx in the Level&nbsp;2 Versions&nbsp;2&ndash;4
 * and Level&nbsp;3 Version&nbsp;1 specifications.</td></tr>  
 * <tr><td>@link XMLErrorCategory_t#LIBSEDML_CAT_UNITS_CONSISTENCY LIBSEDML_CAT_UNITS_CONSISTENCY@endlink</td><td>Category of
 * errors that can occur while validating the units of measurement on
 * quantities in a model.  With respect to the Sed specification, these
 * concern failures in applying the validation rules numbered 105xx in the
 * Level&nbsp;2 Versions&nbsp;2&ndash;4
 * and Level&nbsp;3 Version&nbsp;1 specifications.</td></tr> 
 * <tr><td>@link XMLErrorCategory_t#LIBSEDML_CAT_MATHML_CONSISTENCY LIBSEDML_CAT_MATHML_CONSISTENCY@endlink</td><td>Category of
 * errors that can occur while validating MathML formulas in a model.  With
 * respect to the Sed specification, these concern failures in applying
 * the validation rules numbered 102xx in the Level&nbsp;2 Versions&nbsp;2&ndash;4
 * and Level&nbsp;3 Version&nbsp;1 specifications.</td></tr> 
 * <tr><td>@link XMLErrorCategory_t#LIBSEDML_CAT_SBO_CONSISTENCY LIBSEDML_CAT_SBO_CONSISTENCY@endlink</td><td>Category of errors
 * that can occur while validating SBO identifiers in a model.  With
 * respect to the Sed specification, these concern failures in applying
 * the validation rules numbered 107xx in the Level&nbsp;2 Versions&nbsp;2&ndash;4
 * and Level&nbsp;3 Version&nbsp;1 specifications.</td></tr> 
 * <tr><td>@link XMLErrorCategory_t#LIBSEDML_CAT_OVERDETERMINED_MODEL LIBSEDML_CAT_OVERDETERMINED_MODEL@endlink</td><td>Error in the
 * system of equations in the model: the system is overdetermined,
 * therefore violating a tenet of proper Sed.  With respect to the Sed
 * specification, this is validation rule #10601 in the Sed Level&nbsp;2 Versions&nbsp;2&ndash;4
 * and Level&nbsp;3 Version&nbsp;1 specifications.</td></tr> 
 * <tr><td>@link XMLErrorCategory_t#LIBSEDML_CAT_SEDML_L2V3_COMPAT LIBSEDML_CAT_SEDML_L2V3_COMPAT@endlink</td><td>Category of errors
 * that can only occur during attempted translation from one Level/Version
 * of Sed to another.  This particular category applies to errors
 * encountered while trying to convert a model to Sed Level&nbsp;2
 * Version&nbsp;3.</td></tr> 
 * <tr><td>@link XMLErrorCategory_t#LIBSEDML_CAT_MODELING_PRACTICE LIBSEDML_CAT_MODELING_PRACTICE@endlink</td><td>Category of
 * warnings about recommended good practices involving Sed and
 * computational modeling.  (These are tests performed by libSed and do
 * not have equivalent Sed validation rules.)</td></tr> 
 * <tr><td>@link XMLErrorCategory_t#LIBSEDML_CAT_INTERNAL_CONSISTENCY LIBSEDML_CAT_INTERNAL_CONSISTENCY@endlink</td><td>Category of
 * errors that can occur while validating libSed's internal representation
 * of Sed constructs. (These are tests performed by libSed and do
 * not have equivalent Sed validation rules.)</td></tr> 
 * <tr><td>@link XMLErrorCategory_t#LIBSEDML_CAT_SEDML_L2V4_COMPAT LIBSEDML_CAT_SEDML_L2V4_COMPAT@endlink</td><td>Category of errors
 * that can only occur during attempted translation from one Level/Version
 * of Sed to another.  This particular category applies to errors
 * encountered while trying to convert a model to Sed Level&nbsp;2
 * Version&nbsp;4.</td></tr> 
 * <tr><td>@link XMLErrorCategory_t#LIBSEDML_CAT_SEDML_L3V1_COMPAT LIBSEDML_CAT_SEDML_L3V1_COMPAT@endlink</td><td>Category of errors
 * that can only occur during attempted translation from one Level/Version
 * of Sed to another.  This particular category applies to errors
 * encountered while trying to convert a model to Sed Level&nbsp;3
 * Version&nbsp;1.</td></tr> 
 *
 * </table>
 * </center>
 * 
 * @if clike
 * <h3><a class="anchor" name="SedErrorSeverity_t">SedErrorSeverity_t</a></h3>
 *
 * This is an enumeration of severity codes for SedError diagnostics.
 * User programs receiving an SedError object can use this distinction to
 * check whether the error represents a low-level XML problem or an Sed
 * problem.
 * 
 * In libSed version @htmlinclude libsbml-version.html
 * there are no additional severity codes in SedErrorSeverity_t beyond
 * those defined in @link XMLError::XMLErrorSeverity_t XMLErrorSeverity_t@endlink.
 * 
 * <hr>
 * @endif@if java <h3><a class="anchor"
 * name="SedErrorSeverity_t">Severity codes associated with SedError
 * objects</h3>
 *
 * In libSed version @htmlinclude libsbml-version.html
 * there are no additional severity codes beyond those defined by XMLError.  
 * They are implemented as static integer constants defined in the interface 
 * class <code><a href="libsbmlConstants.html">libsbmlConstants</a></code>, 
 * and have names beginning with <code>LIBSEDML_SEV_</code>.
 * @endif@if python <h3><a class="anchor"
 * name="SedErrorSeverity_t">Severity codes associated with SedError
 * objects</h3>
 *
 * In libSed version @htmlinclude libsbml-version.html
 * there are no additional severity codes beyond those defined by XMLError.
 * They are implemented as static integer constants defined in the
 * interface class @link libsbml libsbml@endlink, and have names beginning
 * with <code>LIBSEDML_SEV_</code>.
 * @endif@~
 */

#ifndef SedError_h
#define SedError_h

#include <sedml/common/extern.h>
#include <sbml/xml/XMLError.h>
#include <sedml/SedNamespaces.h>


LIBSEDML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS

/**
 * Codes for all Sed-level errors and warnings.
 *
 * These are distinguished from the XML layer (LIBLAX) error codes by being
 * numbered > 10000, while the XML layer's codes are < 9999.  Calling
 * programs may wish to check whether a given SedError object's error
 * identifier is actually from SedErrorCode_t or XMLError::XMLErrorCode_t.
 * This distinction corresponds to whether a given error represents a
 * low-level XML problem or an Sed problem.
 */
typedef enum
{
  UnknownError                          = 10000 /*!< Encountered unknown internal libSed error. */
, NotUTF8                               = 10101 /*!< File does not use UTF-8 encoding. */
, UnrecognizedElement                   = 10102 /*!< Encountered unrecognized element. */
, NotSchemaConformant                   = 10103 /*!< Document does not conform to the Sed XML schema. */
, L3NotSchemaConformant                 = 10104 /*!< Document is not well-formed XML. */
, InvalidMathElement                    = 10201 /*!< Invalid MathML. */
, DisallowedMathMLSymbol                = 10202 /*!< Disallowed MathML symbol found. */
, DisallowedMathMLEncodingUse           = 10203 /*!< Use of the MathML 'encoding' attribute is not allowed on this element. */
, DisallowedDefinitionURLUse            = 10204 /*!< Use of the MathML 'definitionURL' attribute is not allowed on this element. */
, BadCsymbolDefinitionURLValue          = 10205 /*!< Invalid <code>&lt;csymbol&gt;</code> 'definitionURL' attribute value. */
, DisallowedMathTypeAttributeUse        = 10206 /*!< Use of the MathML 'type' attribute is not allowed on this element. */
, DisallowedMathTypeAttributeValue      = 10207 /*!< Disallowed MathML 'type' attribute value. */
, LambdaOnlyAllowedInFunctionDef        = 10208 /*!< Use of <code>&lt;lambda&gt;</code> not permitted outside of FunctionDefinition objects. */
, BooleanOpsNeedBooleanArgs             = 10209 /*!< Non-Boolean argument given to Boolean operator. */
, NumericOpsNeedNumericArgs             = 10210 /*!< Non-numerical argument given to numerical operator. */
, ArgsToEqNeedSameType                  = 10211 /*!< Arguments to <code>&lt;eq&gt;</code> and <code>&lt;neq&gt;</code> must have the same data types. */
, PiecewiseNeedsConsistentTypes         = 10212 /*!< Terms in a <code>&lt;piecewise&gt;</code> expression must have consistent data types. */
, PieceNeedsBoolean                     = 10213 /*!< The second argument of a <code>&lt;piece&gt;</code> expression must yield a Boolean value. */
, ApplyCiMustBeUserFunction             = 10214 /*!< A <code>&lt;ci&gt;</code> element in this context must refer to a function definition. */
, ApplyCiMustBeModelComponent           = 10215 /*!< A <code>&lt;ci&gt;</code> element in this context must refer to a model component. */
, KineticLawParametersAreLocalOnly      = 10216 /*!< Cannot use a KineticLaw local parameter outside of its local scope. */
, MathResultMustBeNumeric               = 10217 /*!< A formula's result in this context must be a numerical value. */
, OpsNeedCorrectNumberOfArgs            = 10218 /*!< Incorrect number of arguments given to MathML operator. */
, InvalidNoArgsPassedToFunctionDef      = 10219 /*!< Incorrect number of arguments given to function invocation. */
, DisallowedMathUnitsUse                = 10220 /*!< Attribute 'units' is only permitted on <code>&lt;cn&gt;</code> elements. */
, InvalidUnitsValue                     = 10221 /*!< Invalid value given for the 'units' attribute. */
, DuplicateComponentId                  = 10301 /*!< Duplicate 'id' attribute value. */
, DuplicateUnitDefinitionId             = 10302 /*!< Duplicate unit definition 'id' attribute value. */
, DuplicateLocalParameterId             = 10303 /*!< Duplicate local parameter 'id' attribute value. */
, MultipleAssignmentOrRateRules         = 10304 /*!< Multiple rules for the same variable are not allowed. */
, MultipleEventAssignmentsForId         = 10305 /*!< Multiple event assignments for the same variable are not allowed. */
, EventAndAssignmentRuleForId           = 10306 /*!< An event assignment and an assignment rule must not have the same value for 'variable'. */
, DuplicateMetaId                       = 10307 /*!< Duplicate 'metaid' attribute value. */
, InvalidSBOTermSyntax                  = 10308 /*!< Invalid syntax for an 'sboTerm' attribute value. */
, InvalidMetaidSyntax                   = 10309 /*!< Invalid syntax for a 'metaid' attribute value. */
, InvalidIdSyntax                       = 10310 /*!< Invalid syntax for an 'id' attribute value. */
, InvalidUnitIdSyntax                   = 10311 /*!< Invalid syntax for the identifier of a unit. */
, InvalidNameSyntax                     = 10312 /*!< Invalid syntax for a 'name' attribute value. */
, MissingAnnotationNamespace            = 10401 /*!< Missing declaration of the XML namespace for the annotation. */
, DuplicateAnnotationNamespaces         = 10402 /*!< Multiple annotations using the same XML namespace. */
, SedNamespaceInAnnotation             = 10403 /*!< The Sed XML namespace cannot be used in an Annotation object. */
, MultipleAnnotations                   = 10404 /*!< Only one Annotation object is permitted under a given Sed object. */
, InconsistentArgUnits                  = 10501 /*!< The units of the function call's arguments are not consistent with its definition. */
, InconsistentKineticLawUnitsL3         = 10503 /*!< The kinetic law's units are inconsistent with those of other kinetic laws in the model. */
, AssignRuleCompartmentMismatch         = 10511 /*!< Mismatched units in assignment rule for compartment. */
, AssignRuleSpeciesMismatch             = 10512 /*!< Mismatched units in assignment rule for species. */
, AssignRuleParameterMismatch           = 10513 /*!< Mismatched units in assignment rule for parameter. */
, AssignRuleStoichiometryMismatch       = 10514 /*!< Mismatched units in assignment rule for stoichiometry. */
, InitAssignCompartmenMismatch          = 10521 /*!< Mismatched units in initial assignment to compartment. */
, InitAssignSpeciesMismatch             = 10522 /*!< Mismatched units in initial assignment to species. */
, InitAssignParameterMismatch           = 10523 /*!< Mismatched units in initial assignment to parameter. */
, InitAssignStoichiometryMismatch       = 10524 /*!< Mismatched units in initial assignment to stoichiometry. */
, RateRuleCompartmentMismatch           = 10531 /*!< Mismatched units in rate rule for compartment. */
, RateRuleSpeciesMismatch               = 10532 /*!< Mismatched units in rate rule for species. */
, RateRuleParameterMismatch             = 10533 /*!< Mismatched units in rate rule for parameter. */
, RateRuleStoichiometryMismatch         = 10534 /*!< Mismatched units in rate rule for stoichiometry. */
, KineticLawNotSubstancePerTime         = 10541 /*!< The units of the kinetic law are not 'substance'/'time'. */
, SpeciesInvalidExtentUnits             = 10542 /*!< The species' units are not consistent with units of extent. */
, DelayUnitsNotTime                     = 10551 /*!< The units of the delay expression are not units of time. */
, EventAssignCompartmentMismatch        = 10561 /*!< Mismatched units in event assignment for compartment. */
, EventAssignSpeciesMismatch            = 10562 /*!< Mismatched units in event assignment for species. */
, EventAssignParameterMismatch          = 10563 /*!< Mismatched units in event assignment for parameter. */
, EventAssignStoichiometryMismatch      = 10564 /*!< Mismatched units in event assignment for stoichiometry. */
, PriorityUnitsNotDimensionless         = 10565 /*!< The units of a priority expression must be 'dimensionless'. */
, UpperUnitBound                        = 10599 /*!< Upper boundary of unit validation diagnostic codes. */
, OverdeterminedSystem                  = 10601 /*!< The model is overdetermined. */
, InvalidModelSBOTerm                   = 10701 /*!< Invalid 'sboTerm' attribute value for a Model object. */
, InvalidFunctionDefSBOTerm             = 10702 /*!< Invalid 'sboTerm' attribute value for a FunctionDefinition object. */
, InvalidParameterSBOTerm               = 10703 /*!< Invalid 'sboTerm' attribute value for a Parameter object. */
, InvalidInitAssignSBOTerm              = 10704 /*!< Invalid 'sboTerm' attribute value for an InitialAssignment object. */
, InvalidRuleSBOTerm                    = 10705 /*!< Invalid 'sboTerm' attribute value for a Rule object. */
, InvalidConstraintSBOTerm              = 10706 /*!< Invalid 'sboTerm' attribute value for a Constraint object. */
, InvalidReactionSBOTerm                = 10707 /*!< Invalid 'sboTerm' attribute value for a Reaction object. */
, InvalidSpeciesReferenceSBOTerm        = 10708 /*!< Invalid 'sboTerm' attribute value for a SpeciesReference object. */
, InvalidKineticLawSBOTerm              = 10709 /*!< Invalid 'sboTerm' attribute value for a KineticLaw object. */
, InvalidEventSBOTerm                   = 10710 /*!< Invalid 'sboTerm' attribute value for an Event object. */
, InvalidEventAssignmentSBOTerm         = 10711 /*!< Invalid 'sboTerm' attribute value for an EventAssignment object. */
, InvalidCompartmentSBOTerm             = 10712 /*!< Invalid 'sboTerm' attribute value for a Compartment object. */
, InvalidSpeciesSBOTerm                 = 10713 /*!< Invalid 'sboTerm' attribute value for a Species object. */
, InvalidCompartmentTypeSBOTerm         = 10714 /*!< Invalid 'sboTerm' attribute value for a CompartmentType object. */
, InvalidSpeciesTypeSBOTerm             = 10715 /*!< Invalid 'sboTerm' attribute value for a SpeciesType object. */
, InvalidTriggerSBOTerm                 = 10716 /*!< Invalid 'sboTerm' attribute value for an Event Trigger object. */
, InvalidDelaySBOTerm                   = 10717 /*!< Invalid 'sboTerm' attribute value for an Event Delay object. */
, NotesNotInXHTMLNamespace              = 10801 /*!< Notes must be placed in the XHTML XML namespace. */
, NotesContainsXMLDecl                  = 10802 /*!< XML declarations are not permitted in Notes objects. */
, NotesContainsDOCTYPE                  = 10803 /*!< XML DOCTYPE elements are not permitted in Notes objects. */
, InvalidNotesContent                   = 10804 /*!< Invalid notes content found. */
, OnlyOneNotesElementAllowed            = 10805 /*!< Only one Notes subobject is permitted on a given Sed object. */
, InvalidNamespaceOnSed                = 20101 /*!< Invalid XML namespace for the Sed container element. */
, MissingOrInconsistentLevel            = 20102 /*!< Missing or inconsistent value for the 'level' attribute. */
, MissingOrInconsistentVersion          = 20103 /*!< Missing or inconsistent value for the 'version' attribute. */
, PackageNSMustMatch                    = 20104 /*!< Inconsistent or invalid Sed Level/Version for the package namespace declaration. */
, LevelPositiveInteger                  = 20105 /*!< The 'level' attribute must have a positive integer value. */
, VersionPositiveInteger                = 20106 /*!< The 'version' attribute must have a positive integer value. */
, AllowedAttributesOnSed               = 20108 /*!< Invalid attribute found on the Sed container element. */
, L3PackageOnLowerSed                  = 20109 /*!< An L3 package ns found on the Sed container element.. */
, MissingModel                          = 20201 /*!< No model definition found. */
, IncorrectOrderInModel                 = 20202 /*!< Incorrect ordering of components within the Model object. */
, EmptyListElement                      = 20203 /*!< Empty ListOf___ object found. */
, NeedCompartmentIfHaveSpecies          = 20204 /*!< The presence of a species requires a compartment. */
, OneOfEachListOf                       = 20205 /*!< Only one of each kind of ListOf___ object is allowed inside a Model object. */
, OnlyFuncDefsInListOfFuncDefs          = 20206 /*!< Only FunctionDefinition, Notes and Annotation objects are allowed in ListOfFunctionDefinitions. */
, OnlyUnitDefsInListOfUnitDefs          = 20207 /*!< Only UnitDefinition, Notes and Annotation objects are allowed in ListOfUnitDefinitions objects. */
, OnlyCompartmentsInListOfCompartments  = 20208 /*!< Only Compartment, Notes and Annotation objects are allowed in ListOfCompartments objects. */
, OnlySpeciesInListOfSpecies            = 20209 /*!< Only Species, Notes and Annotation objects are allowed in ListOfSpecies objects. */
, OnlyParametersInListOfParameters      = 20210 /*!< Only Parameter, Notes and Annotation objects are allowed in ListOfParameters objects. */
, OnlyInitAssignsInListOfInitAssigns    = 20211 /*!< Only InitialAssignment, Notes and Annotation objects are allowed in ListOfInitialAssignments objects. */
, OnlyRulesInListOfRules                = 20212 /*!< Only Rule, Notes and Annotation objects are allowed in ListOfRules objects. */
, OnlyConstraintsInListOfConstraints    = 20213 /*!< Only Constraint, Notes and Annotation objects are allowed in ListOfConstraints objects. */
, OnlyReactionsInListOfReactions        = 20214 /*!< Only Reaction, Notes and Annotation objects are allowed in ListOfReactions objects. */
, OnlyEventsInListOfEvents              = 20215 /*!< Only Event, Notes and Annotation objects are allowed in ListOfEvents objects. */
, L3ConversionFactorOnModel             = 20216 /*!< A 'conversionFactor' attribute value must reference a Parameter object. */
, L3TimeUnitsOnModel                    = 20217 /*!< Invalid 'timeUnits' attribute value. */
, L3VolumeUnitsOnModel                  = 20218 /*!< Invalid 'volumeUnits' attribute value. */
, L3AreaUnitsOnModel                    = 20219 /*!< Invalid 'areaUnits' attribute value. */
, L3LengthUnitsOnModel                  = 20220 /*!< Invalid 'lengthUnits' attribute value. */
, L3ExtentUnitsOnModel                  = 20221 /*!< Invalid 'extentUnits' attribute value. */
, AllowedAttributesOnModel              = 20222 /*!< Invalid attribute found on the Model object. */
, AllowedAttributesOnListOfFuncs        = 20223 /*!< Invalid attribute found on the ListOfFunctionDefinitions object. */
, AllowedAttributesOnListOfUnitDefs     = 20224 /*!< Invalid attribute found on the ListOfUnitDefinitions object. */
, AllowedAttributesOnListOfComps        = 20225 /*!< Invalid attribute found on the ListOfCompartments object. */
, AllowedAttributesOnListOfSpecies      = 20226 /*!< Invalid attribute found on the ListOfSpecies object. */
, AllowedAttributesOnListOfParams       = 20227 /*!< Invalid attribute found on the ListOfParameters object. */
, AllowedAttributesOnListOfInitAssign   = 20228 /*!< Invalid attribute found on the ListOfInitialAssignments object. */
, AllowedAttributesOnListOfRules        = 20229 /*!< Invalid attribute found on the ListOfRules object. */
, AllowedAttributesOnListOfConstraints  = 20230 /*!< Invalid attribute found on the ListOfConstraints object. */
, AllowedAttributesOnListOfReactions    = 20231 /*!< Invalid attribute found on the ListOfReactions object. */
, AllowedAttributesOnListOfEvents       = 20232 /*!< Invalid attribute found on the ListOfEvents object. */
, FunctionDefMathNotLambda              = 20301 /*!< Invalid expression found in the function definition. */
, InvalidApplyCiInLambda                = 20302 /*!< Invalid forward reference in the MathML <code>&lt;apply&gt;</code><code>&lt;ci&gt;</code>...<code>&lt;/ci&gt;</code><code>&lt;/apply&gt;</code> expression. */
, RecursiveFunctionDefinition           = 20303 /*!< Recursive function definitions are not permitted. */
, InvalidCiInLambda                     = 20304 /*!< Invalid <code>&lt;ci&gt;</code> reference found inside the <code>&lt;lambda&gt;</code> mathematical formula. */
, InvalidFunctionDefReturnType          = 20305 /*!< A function's return type must be either a number or a Boolean. */
, OneMathElementPerFunc                 = 20306 /*!< A FunctionDefinition object must contain one <code>&lt;math&gt;</code> element. */
, AllowedAttributesOnFunc               = 20307 /*!< Invalid attribute found on the FunctionDefinition object. */
, InvalidUnitDefId                      = 20401 /*!< Invalid 'id' attribute value for a UnitDefinition object. */
, InvalidSubstanceRedefinition          = 20402 /*!< Invalid redefinition of built-in type 'substance'. */
, InvalidLengthRedefinition             = 20403 /*!< Invalid redefinition of built-in type 'length'. */
, InvalidAreaRedefinition               = 20404 /*!< Invalid redefinition of built-in type name 'area'. */
, InvalidTimeRedefinition               = 20405 /*!< Invalid redefinition of built-in type name 'time'. */
, InvalidVolumeRedefinition             = 20406 /*!< Invalid redefinition of built-in type name 'volume'. */
, VolumeLitreDefExponentNotOne          = 20407 /*!< Must use 'exponent'=1 when defining 'volume' in terms of litres. */
, VolumeMetreDefExponentNot3            = 20408 /*!< Must use 'exponent'=3 when defining 'volume' in terms of metres. */
, EmptyListOfUnits                      = 20409 /*!< An empty list of Unit objects is not permitted in a UnitDefinition object. */
, InvalidUnitKind                       = 20410 /*!< Invalid value for the 'kind' attribute of a UnitDefinition object. */
, OffsetNoLongerValid                   = 20411 /*!< Unit attribute 'offset' is not supported in this Level+Version of Sed. */
, CelsiusNoLongerValid                  = 20412 /*!< Unit name 'Celsius' is not defined in this Level+Version of Sed. */
, EmptyUnitListElement                  = 20413 /*!< A ListOfUnits object must not be empty. */
, OneListOfUnitsPerUnitDef              = 20414 /*!< At most one ListOfUnits object is allowed inside a UnitDefinition object. */
, OnlyUnitsInListOfUnits                = 20415 /*!< Only Unit, Notes and Annotation objects are allowed in ListOfUnits objects. */
, AllowedAttributesOnUnitDefinition     = 20419 /*!< Invalid attribute found on the UnitDefinition object. */
, AllowedAttributesOnListOfUnits        = 20420 /*!< Invalid attribute found on the ListOfUnits object. */
, AllowedAttributesOnUnit               = 20421 /*!< Invalid attribute found on the Unit object. */
, ZeroDimensionalCompartmentSize        = 20501 /*!< Invalid use of the 'size' attribute for a zero-dimensional compartment. */
, ZeroDimensionalCompartmentUnits       = 20502 /*!< Invalid use of the 'units' attribute for a zero-dimensional compartment. */
, ZeroDimensionalCompartmentConst       = 20503 /*!< Zero-dimensional compartments must be defined to be constant. */
, UndefinedOutsideCompartment           = 20504 /*!< Invalid value for the 'outside' attribute of a Compartment object. */
, RecursiveCompartmentContainment       = 20505 /*!< Recursive nesting of compartments via the 'outside' attribute is not permitted. */
, ZeroDCompartmentContainment           = 20506 /*!< Invalid nesting of zero-dimensional compartments. */
, Invalid1DCompartmentUnits             = 20507 /*!< Invalid value for the 'units' attribute of a one-dimensional compartment. */
, Invalid2DCompartmentUnits             = 20508 /*!< Invalid value for the 'units' attribute of a two-dimensional compartment. */
, Invalid3DCompartmentUnits             = 20509 /*!< Invalid value for the 'units' attribute of a three-dimensional compartment. */
, InvalidCompartmentTypeRef             = 20510 /*!< Invalid value for the 'compartmentType' attribute of a compartment. */
, OneDimensionalCompartmentUnits        = 20511 /*!< No units defined for 1-D compartment. */
, TwoDimensionalCompartmentUnits        = 20512 /*!< No units defined for 2-D compartment. */
, ThreeDimensionalCompartmentUnits      = 20513 /*!< No units defined for 3-D Compartment object. */
, AllowedAttributesOnCompartment        = 20517 /*!< Invalid attribute found on Compartment object. */
, NoUnitsOnCompartment                  = 20518 /*!< No units defined for Compartment object. */
, InvalidSpeciesCompartmentRef          = 20601 /*!< Invalid value found for Species 'compartment' attribute. */
, HasOnlySubsNoSpatialUnits             = 20602 /*!< Attribute 'spatialSizeUnits' must not be set if 'hasOnlySubstanceUnits'='true'. */
, NoSpatialUnitsInZeroD                 = 20603 /*!< Attribute 'spatialSizeUnits' must not be set if the compartment is zero-dimensional. */
, NoConcentrationInZeroD                = 20604 /*!< Attribute 'initialConcentration' must not be set if the compartment is zero-dimensional. */
, SpatialUnitsInOneD                    = 20605 /*!< Invalid value for 'spatialSizeUnits' attribute of a one-dimensional compartment. */
, SpatialUnitsInTwoD                    = 20606 /*!< Invalid value for the 'spatialSizeUnits' attribute of a two-dimensional compartment. */
, SpatialUnitsInThreeD                  = 20607 /*!< Invalid value for the 'spatialSizeUnits' attribute of a three-dimensional compartment. */
, InvalidSpeciesSusbstanceUnits         = 20608 /*!< Invalid value for a Species 'units' attribute. */
, BothAmountAndConcentrationSet         = 20609 /*!< Cannot set both 'initialConcentration' and 'initialAmount' attributes simultaneously. */
, NonBoundarySpeciesAssignedAndUsed     = 20610 /*!< Cannot use a non-boundary species in both reactions and rules simultaneously. */
, NonConstantSpeciesUsed                = 20611 /*!< Cannot use a constant, non-boundary species as a reactant or product. */
, InvalidSpeciesTypeRef                 = 20612 /*!< Invalid value for the 'speciesType' attribute of a species. */
, MultSpeciesSameTypeInCompartment      = 20613 /*!< Cannot have multiple species of the same species type in the same compartment. */
, MissingSpeciesCompartment             = 20614 /*!< Missing value for the 'compartment' attribute. */
, SpatialSizeUnitsRemoved               = 20615 /*!< Attribute 'spatialSizeUnits' is not supported in this Level+Version of Sed. */
, SubstanceUnitsOnSpecies               = 20616 /*!< No substance units defined for the species. */
, ConversionFactorOnSpecies             = 20617 /*!< Invalid value for the 'conversionFactor' attribute. */
, AllowedAttributesOnSpecies            = 20623 /*!< Invalid attribute found on Species object. */
, InvalidParameterUnits                 = 20701 /*!< Invalid value for the 'units' attribute of a Parameter object. */
, ParameterUnits                        = 20702 /*!< No units defined for the parameter. */
, ConversionFactorMustConstant          = 20705 /*!< A conversion factor must reference a Parameter object declared to be a constant. */
, AllowedAttributesOnParameter          = 20706 /*!< Invalid attribute found on Parameter object. */
, InvalidInitAssignSymbol               = 20801 /*!< Invalid value for the 'symbol' attribute of an InitialAssignment object. */
, MultipleInitAssignments               = 20802 /*!< Multiple initial assignments for the same 'symbol' value are not allowed. */
, InitAssignmentAndRuleForSameId        = 20803 /*!< Cannot set a value using both an initial assignment and an assignment rule simultaneously. */
, OneMathElementPerInitialAssign        = 20804 /*!< An InitialAssignment object must contain one <code>&lt;math&gt;</code> element. */
, AllowedAttributesOnInitialAssign      = 20805 /*!< Invalid attribute found on an InitialAssignment object. */
, InvalidAssignRuleVariable             = 20901 /*!< Invalid value for the 'variable' attribute of an AssignmentRule object. */
, InvalidRateRuleVariable               = 20902 /*!< Invalid value for the 'variable' attribute of a RateRule object. */
, AssignmentToConstantEntity            = 20903 /*!< An assignment rule cannot assign an entity declared to be constant. */
, RateRuleForConstantEntity             = 20904 /*!< A rate rule cannot assign an entity declared to be constant. */
, RepeatedRule10304                     = 20905
, CircularRuleDependency                = 20906 /*!< Circular dependencies involving rules and reactions are not permitted. */
, OneMathElementPerRule                 = 20907 /*!< A rule object must contain one <code>&lt;math&gt;</code> element. */
, AllowedAttributesOnAssignRule         = 20908 /*!< Invalid attribute found on an AssignmentRule object. */
, AllowedAttributesOnRateRule           = 20909 /*!< Invalid attribute found on a RateRule object. */
, AllowedAttributesOnAlgRule            = 20910 /*!< Invalid attribute found on an AlgebraicRule object. */
, ConstraintMathNotBoolean              = 21001 /*!< A Constraint object's <code>&lt;math&gt;</code> must evaluate to a Boolean value. */
, IncorrectOrderInConstraint            = 21002 /*!< Subobjects inside the Constraint object are not in the prescribed order. */
, ConstraintNotInXHTMLNamespace         = 21003 /*!< A Constraint's Message subobject must be in the XHTML XML namespace. */
, ConstraintContainsXMLDecl             = 21004 /*!< XML declarations are not permitted within Constraint's Message objects. */
, ConstraintContainsDOCTYPE             = 21005 /*!< XML DOCTYPE elements are not permitted within Constraint's Message objects. */
, InvalidConstraintContent              = 21006 /*!< Invalid content for a Constraint object's Message object. */
, OneMathElementPerConstraint           = 21007 /*!< A Constraint object must contain one <code>&lt;math&gt;</code> element. */
, OneMessageElementPerConstraint        = 21008 /*!< A Constraint object must contain one Message subobject. */
, AllowedAttributesOnConstraint         = 21009 /*!< Invalid attribute found on Constraint object. */
, NoReactantsOrProducts                 = 21101 /*!< Cannot have a reaction with neither reactants nor products. */
, IncorrectOrderInReaction              = 21102 /*!< Subobjects inside the Reaction object are not in the prescribed order. */
, EmptyListInReaction                   = 21103 /*!< Reaction components, if present, cannot be empty. */
, InvalidReactantsProductsList          = 21104 /*!< Invalid object found in the list of reactants or products. */
, InvalidModifiersList                  = 21105 /*!< Invalid object found in the list of modifiers. */
, OneSubElementPerReaction              = 21106 /*!< A Reaction object can only contain one of each allowed type of object. */
, CompartmentOnReaction                 = 21107 /*!< Invalid value for the Reaction 'compartment' attribute. */
, AllowedAttributesOnReaction           = 21110 /*!< Invalid attribute for a Reaction object. */
, InvalidSpeciesReference               = 21111 /*!< Invalid 'species' attribute value in SpeciesReference object. */
, RepeatedRule20611                     = 21112
, BothStoichiometryAndMath              = 21113 /*!< The 'stoichiometry' attribute and StoichiometryMath subobject are mutually exclusive. */
, AllowedAttributesOnSpeciesReference   = 21116 /*!< Invalid attribute found on the SpeciesReference object. */
, AllowedAttributesOnModifier           = 21117 /*!< Invalid attribute found on the ModifierSpeciesReference object. */
, UndeclaredSpeciesRef                  = 21121 /*!< Unknown species referenced in the kinetic law <code>&lt;math&gt;</code> formula. */
, IncorrectOrderInKineticLaw            = 21122 /*!< Incorrect ordering of components in the KineticLaw object. */
, EmptyListInKineticLaw                 = 21123 /*!< The list of parameters, if present, cannot be empty. */
, NonConstantLocalParameter             = 21124 /*!< Parameters local to a KineticLaw object must have a 'constant' attribute value of 'true'. */
, SubsUnitsNoLongerValid                = 21125 /*!< Attribute 'substanceUnits' is not supported in this Level+Version of Sed. */
, TimeUnitsNoLongerValid                = 21126 /*!< Attribute 'timeUnits' is not supported in this Level+Version of Sed. */
, OneListOfPerKineticLaw                = 21127 /*!< Only one ListOfLocalParameters object is permitted within a KineticLaw object. */
, OnlyLocalParamsInListOfLocalParams    = 21128 /*!< Only LocalParameter, Notes and Annotation objects are allowed in ListOfLocalParameter objects. */
, AllowedAttributesOnListOfLocalParam   = 21129 /*!< Invalid attribute found on the ListOfLocalParameters object. */
, OneMathPerKineticLaw                  = 21130 /*!< Only one <code>&lt;math&gt;</code> element is allowed in a KineticLaw object. */
, UndeclaredSpeciesInStoichMath         = 21131 /*!< Unknown species referenced in the StoichiometryMath object's <code>&lt;math&gt;</code> formula. */
, AllowedAttributesOnKineticLaw         = 21132 /*!< Invalid attribute found on the KineticLaw object. */
, AllowedAttributesOnListOfSpeciesRef   = 21150 /*!< Invalid attribute found on the ListOfSpeciesReferences object. */
, AllowedAttributesOnListOfMods         = 21151 /*!< Invalid attribute found on the ListOfModifiers object. */
, AllowedAttributesOnLocalParameter     = 21172 /*!< Invalid attribute found on the LocalParameter object. */
, MissingTriggerInEvent                 = 21201 /*!< The Event object is missing a Trigger subobject. */
, TriggerMathNotBoolean                 = 21202 /*!< A Trigger object's <code>&lt;math&gt;</code> expression must evaluate to a Boolean value. */
, MissingEventAssignment                = 21203 /*!< The Event object is missing an EventAssignment subobject. */
, TimeUnitsEvent                        = 21204 /*!< Units referenced by 'timeUnits' attribute are not compatible with units of time. */
, IncorrectOrderInEvent                 = 21205 /*!< Incorrect ordering of components in Event object. */
, ValuesFromTriggerTimeNeedDelay        = 21206 /*!< Attribute 'useValuesFromTriggerTime'='false', but the Event object does not define a delay. */
, DelayNeedsValuesFromTriggerTime       = 21207 /*!< The use of a Delay object requires the Event attribute 'useValuesFromTriggerTime'. */
, OneMathPerTrigger                     = 21209 /*!< A Trigger object must have one <code>&lt;math&gt;</code> element. */
, OneMathPerDelay                       = 21210 /*!< A Delay object must have one <code>&lt;math&gt;</code> element. */
, InvalidEventAssignmentVariable        = 21211 /*!< Invalid 'variable' attribute value in Event object. */
, EventAssignmentForConstantEntity      = 21212 /*!< An EventAssignment object cannot assign to a component having attribute 'constant'='true'. */
, OneMathPerEventAssignment             = 21213 /*!< An EventAssignment object must have one <code>&lt;math&gt;</code> element. */
, AllowedAttributesOnEventAssignment    = 21214 /*!< Invalid attribute found on the EventAssignment object. */
, OnlyOneDelayPerEvent                  = 21221 /*!< An Event object can only have one Delay subobject. */
, OneListOfEventAssignmentsPerEvent     = 21222 /*!< An Event object can only have one ListOfEventAssignments subobject. */
, OnlyEventAssignInListOfEventAssign    = 21223 /*!< Only EventAssignment, Notes and Annotation objects are allowed in ListOfEventAssignments. */
, AllowedAttributesOnListOfEventAssign  = 21224 /*!< Invalid attribute found on the ListOfEventAssignments object. */
, AllowedAttributesOnEvent              = 21225 /*!< Invalid attribute found on the Event object. */
, AllowedAttributesOnTrigger            = 21226 /*!< Invalid attribute found on the Trigger object. */
, AllowedAttributesOnDelay              = 21227 /*!< Invalid attribute found on the Delay object. */
, PersistentNotBoolean                  = 21228 /*!< The Trigger attribute 'persistent' must evaluate to a Boolean value. */
, InitialValueNotBoolean                = 21229 /*!< The Trigger attribute 'initialValue' must evaluate to a Boolean value. */
, OnlyOnePriorityPerEvent               = 21230 /*!< An Event object can only have one Priority subobject. */
, OneMathPerPriority                    = 21231 /*!< A Priority object must have one <code>&lt;math&gt;</code> element. */
, AllowedAttributesOnPriority           = 21232 /*!< Invalid attribute found on the Priority object. */
, GeneralWarningNotSpecified            = 29999 /*!< Unknown error. */
, CompartmentShouldHaveSize             = 80501 /*!< It's best to define a size for every compartment in a model. */
, SpeciesShouldHaveValue                = 80601 /*!< It's best to define an initial amount or initial concentration for every species in a model. */
, ParameterShouldHaveUnits              = 80701 /*!< It's best to declare units for every parameter in a model. */
, LocalParameterShadowsId               = 81121 /*!< Local parameters defined within a kinetic law shadow global object symbols. */
, LibSedAdditionalCodesLowerBound      = 90000 /*!< Lower boundary of libSed-specific diagnostic codes. */
, CannotConvertToL1V1                   = 90001 /*!< Cannot convert to Sed Level 1 Version 1. */
, NoEventsInL1                          = 91001 /*!< Sed Level 1 does not support events. */
, NoFunctionDefinitionsInL1             = 91002 /*!< Sed Level 1 does not support function definitions. */
, NoConstraintsInL1                     = 91003 /*!< Sed Level 1 does not support constraints. */
, NoInitialAssignmentsInL1              = 91004 /*!< Sed Level 1 does not support initial assignments. */
, NoSpeciesTypesInL1                    = 91005 /*!< Sed Level 1 does not support species types. */
, NoCompartmentTypeInL1                 = 91006 /*!< Sed Level 1 does not support compartment types. */
, NoNon3DCompartmentsInL1               = 91007 /*!< Sed Level 1 only supports three-dimensional compartments. */
, NoFancyStoichiometryMathInL1          = 91008 /*!< Sed Level 1 does not support non-integer nor non-rational stoichiometry formulas. */
, NoNonIntegerStoichiometryInL1         = 91009 /*!< Sed Level 1 does not support non-integer 'stoichiometry' attribute values. */
, NoUnitMultipliersOrOffsetsInL1        = 91010 /*!< Sed Level 1 does not support multipliers or offsets in unit definitions. */
, SpeciesCompartmentRequiredInL1        = 91011 /*!< In Sed Level 1, a value for 'compartment' is mandatory in species definitions. */
, NoSpeciesSpatialSizeUnitsInL1         = 91012 /*!< Sed Level 1 does not support species 'spatialSizeUnits' settings. */
, NoSBOTermsInL1                        = 91013 /*!< Sed Level 1 does not support the 'sboTerm' attribute. */
, StrictUnitsRequiredInL1               = 91014 /*!< Sed Level 1 requires strict unit consistency. */
, ConversionFactorNotInL1               = 91015 /*!< Sed Level 1 does not support the 'conversionFactor' attribute. */
, CompartmentNotOnL1Reaction            = 91016 /*!< Sed Level 1 does not support the 'compartment' attribute on Reaction objects. */
, ExtentUnitsNotSubstance               = 91017 /*!< Units of extent must be compatible with units of substance. */
, GlobalUnitsNotDeclared                = 91018 /*!< Global units must be refer to unit kind or unitDefinition.. */
, HasOnlySubstanceUnitsNotinL1          = 91019 /*!< The concept of hasOnlySubstanceUnits was not available in Sed Level 1.. */
, AvogadroNotSupported                  = 91020 /*!< Avogadro not supported in Levels 2 and 1.. */
, NoConstraintsInL2v1                   = 92001 /*!< Sed Level 2 Version 1 does not support Constraint objects. */
, NoInitialAssignmentsInL2v1            = 92002 /*!< Sed Level 2 Version 1 does not support InitialAssignment objects. */
, NoSpeciesTypeInL2v1                   = 92003 /*!< Sed Level 2 Version 1 does not support SpeciesType objects. */
, NoCompartmentTypeInL2v1               = 92004 /*!< Sed Level 2 Version 1 does not support CompartmentType objects. */
, NoSBOTermsInL2v1                      = 92005 /*!< Sed Level 2 Version 1 does not support the 'sboTerm' attribute. */
, NoIdOnSpeciesReferenceInL2v1          = 92006 /*!< Sed Level 2 Version 1 does not support the 'id' attribute on SpeciesReference objects. */
, NoDelayedEventAssignmentInL2v1        = 92007 /*!< Sed Level 2 Version 1 does not support the 'useValuesFromTriggerTime' attribute. */
, StrictUnitsRequiredInL2v1             = 92008 /*!< Sed Level 2 Version 1 requires strict unit consistency. */
, IntegerSpatialDimensions              = 92009 /*!< Sed Level 2 Version 1 requires that compartments have spatial dimensions of 0-3. */
, StoichiometryMathNotYetSupported      = 92010 /*!< Conversion to StoichiometryMath objects not yet supported. */
, PriorityLostFromL3                    = 92011 /*!< Sed Level 2 Version 1 does not support priorities on Event objects. */
, NonPersistentNotSupported             = 92012 /*!< Sed Level 2 Version 1 does not support the 'persistent' attribute on Trigger objects. */
, InitialValueFalseEventNotSupported    = 92013 /*!< Sed Level 2 Version 1 does not support the 'initialValue' attribute on Trigger objects. */
, SBOTermNotUniversalInL2v2             = 93001 /*!< The 'sboTerm' attribute is invalid for this component in Sed Level 2 Version 2. */
, NoUnitOffsetInL2v2                    = 93002 /*!< This Level+Version of Sed does not support the 'offset' attribute on Unit objects. */
, NoKineticLawTimeUnitsInL2v2           = 93003 /*!< This Level+Version of Sed does not support the 'timeUnits' attribute on KineticLaw objects. */
, NoKineticLawSubstanceUnitsInL2v2      = 93004 /*!< This Level+Version of Sed does not support the 'substanceUnits' attribute on KineticLaw objects. */
, NoDelayedEventAssignmentInL2v2        = 93005 /*!< This Level+Version of Sed does not support the 'useValuesFromTriggerTime' attribute. */
, ModelSBOBranchChangedBeyondL2v2       = 93006 /*!< The allowable 'sboTerm' attribute values for Model objects differ for this Sed Level+Version. */
, StrictUnitsRequiredInL2v2             = 93007 /*!< Sed Level 2 Version 2 requires strict unit consistency. */
, StrictSBORequiredInL2v2               = 93008 /*!< Sed Level 2 Version 2 requires strict SBO term consistency. */
, DuplicateAnnotationInvalidInL2v2      = 93009 /*!< Duplicate top-level annotations are invalid in Sed Level 2 Version 2. */
, NoUnitOffsetInL2v3                    = 94001 /*!< This Level+Version of Sed does not support the 'offset' attribute on Unit objects. */
, NoKineticLawTimeUnitsInL2v3           = 94002 /*!< This Level+Version of Sed does not support the 'timeUnits' attribute on KineticLaw objects. */
, NoKineticLawSubstanceUnitsInL2v3      = 94003 /*!< This Level+Version of Sed does not support the 'substanceUnits' attribute on KineticLaw objects. */
, NoSpeciesSpatialSizeUnitsInL2v3       = 94004 /*!< This Level+Version of Sed does not support the 'spatialSizeUnit' attribute on Species objects. */
, NoEventTimeUnitsInL2v3                = 94005 /*!< This Level+Version of Sed does not support the 'timeUnits' attribute on Event objects. */
, NoDelayedEventAssignmentInL2v3        = 94006 /*!< This Level+Version of Sed does not support the 'useValuesFromTriggerTime' attribute. */
, ModelSBOBranchChangedBeyondL2v3       = 94007 /*!< The allowable 'sboTerm' attribute values for Model objects differ for this Sed Level+Version. */
, StrictUnitsRequiredInL2v3             = 94008 /*!< Sed Level 2 Version 3 requires strict unit consistency. */
, StrictSBORequiredInL2v3               = 94009 /*!< Sed Level 2 Version 3 requires strict SBO term consistency. */
, DuplicateAnnotationInvalidInL2v3      = 94010 /*!< Duplicate top-level annotations are invalid in Sed Level 2 Version 3. */
, NoUnitOffsetInL2v4                    = 95001 /*!< This Level+Version of Sed does not support the 'offset' attribute on Unit objects. */
, NoKineticLawTimeUnitsInL2v4           = 95002 /*!< This Level+Version of Sed does not support the 'timeUnits' attribute on KineticLaw objects. */
, NoKineticLawSubstanceUnitsInL2v4      = 95003 /*!< This Level+Version of Sed does not support the 'substanceUnits' attribute on KineticLaw objects. */
, NoSpeciesSpatialSizeUnitsInL2v4       = 95004 /*!< This Level+Version of Sed does not support the 'spatialSizeUnit' attribute on Species objects. */
, NoEventTimeUnitsInL2v4                = 95005 /*!< This Level+Version of Sed does not support the 'timeUnits' attribute on Event objects. */
, ModelSBOBranchChangedInL2v4           = 95006 /*!< The allowable 'sboTerm' attribute values for Model objects differ for this Sed Level+Version. */
, DuplicateAnnotationInvalidInL2v4      = 95007 /*!< Duplicate top-level annotations are invalid in Sed Level 2 Version 4. */
, NoSpeciesTypeInL3v1                   = 96001 /*!< Sed Level 3 Version 1 does not support SpeciesType objects. */
, NoCompartmentTypeInL3v1               = 96002 /*!< Sed Level 3 Version 1 does not support CompartmentType objects. */
, NoUnitOffsetInL3v1                    = 96003 /*!< This Level+Version of Sed does not support the 'offset' attribute on Unit objects. */
, NoKineticLawTimeUnitsInL3v1           = 96004 /*!< This Level+Version of Sed does not support the 'timeUnits' attribute on KineticLaw objects. */
, NoKineticLawSubstanceUnitsInL3v1      = 96005 /*!< This Level+Version of Sed does not support the 'substanceUnits' attribute on KineticLaw objects. */
, NoSpeciesSpatialSizeUnitsInL3v1       = 96006 /*!< This Level+Version of Sed does not support the 'spatialSizeUnit' attribute on Species objects. */
, NoEventTimeUnitsInL3v1                = 96007 /*!< This Level+Version of Sed does not support the 'timeUnits' attribute on Event objects. */
, ModelSBOBranchChangedInL3v1           = 96008 /*!< The allowable 'sboTerm' attribute values for Model objects differ for this Sed Level+Version. */
, DuplicateAnnotationInvalidInL3v1      = 96009 /*!< Duplicate top-level annotations are invalid in Sed Level 3 Version 1. */
, NoCompartmentOutsideInL3v1            = 96010 /*!< This Level+Version of Sed does not support the 'outside' attribute on Compartment objects. */
, NoStoichiometryMathInL3v1             = 96011 /*!< This Level+Version of Sed does not support the StoichiometryMath object. */
, InvalidSedLevelVersion               = 99101 /*!< Unknown Level+Version combination of Sed. */
, AnnotationNotesNotAllowedLevel1       = 99104 /*!< Annotation objects on the Sed container element are not permitted in Sed Level 1. */
, InvalidRuleOrdering                   = 99106 /*!< Invalid ordering of rules. */
, RequiredPackagePresent                = 99107 /*!< The Sed document requires an Sed Level 3 package unavailable in this software. */
, UnrequiredPackagePresent              = 99108 /*!< The Sed document uses an Sed Level 3 package unavailable in this software. */
, PackageRequiredShouldBeFalse          = 99109 /*!< This package expects required to be false.. */
, SubsUnitsAllowedInKL                  = 99127 /*!< Disallowed value for attribute 'substanceUnits' on KineticLaw object. */
, TimeUnitsAllowedInKL                  = 99128 /*!< Disallowed value for attribute 'timeUnits' on KineticLaw object. */
, FormulaInLevel1KL                     = 99129 /*!< Only predefined functions are allowed in Sed Level 1 formulas. */
, L3SubstanceUnitsOnModel               = 99130 /*!< Invalid 'substanceUnits' attribute value. */
, TimeUnitsRemoved                      = 99206 /*!< This Level+Version of Sed does not support the 'timeUnits' attribute on Event objects. */
, BadMathML                             = 99219 /*!< Invalid MathML expression. */
, FailedMathMLReadOfDouble              = 99220 /*!< Missing or invalid floating-point number in MathML expression. */
, FailedMathMLReadOfInteger             = 99221 /*!< Missing or invalid integer in MathML expression. */
, FailedMathMLReadOfExponential         = 99222 /*!< Missing or invalid exponential expression in MathML. */
, FailedMathMLReadOfRational            = 99223 /*!< Missing or invalid rational expression in MathML. */
, BadMathMLNodeType                     = 99224 /*!< Invalid MathML element. */
, NoTimeSymbolInFunctionDef             = 99301 /*!< Use of <code>&lt;csymbol&gt;</code> for 'time' not allowed within FunctionDefinition objects. */
, NoBodyInFunctionDef                   = 99302 /*!< There must be a <code>&lt;lambda&gt;</code> body within the <code>&lt;math&gt;</code> element of a FunctionDefinition object. */
, DanglingUnitSIdRef                    = 99303 /*!< Units must refer to valid unit or unitDefinition. */
, RDFMissingAboutTag                    = 99401 /*!< RDF missing the <code>&lt;about&gt;</code> tag.. */
, RDFEmptyAboutTag                      = 99402 /*!< RDF empty <code>&lt;about&gt;</code> tag.. */
, RDFAboutTagNotMetaid                  = 99403 /*!< RDF <code>&lt;about&gt;</code> tag is not metaid.. */
, RDFNotCompleteModelHistory            = 99404 /*!< RDF does not contain valid ModelHistory.. */
, RDFNotModelHistory                    = 99405 /*!< RDF does not result in a ModelHistory.. */
, AnnotationNotElement                  = 99406 /*!< Annotation must contain element.. */
, InconsistentArgUnitsWarnings          = 99502
, InconsistentPowerUnitsWarnings        = 99503
, InconsistentExponUnitsWarnings        = 99504
, UndeclaredUnits                       = 99505 /*!< Missing unit declarations on parameters or literal numbers in expression. */
, UndeclaredTimeUnitsL3                 = 99506 /*!< Unable to verify consistency of units: the unit of time has not been declared. */
, UndeclaredExtentUnitsL3               = 99507 /*!< Unable to verify consistency of units: the units of reaction extent have not been declared. */
, UndeclaredObjectUnitsL3               = 99508 /*!< Unable to verify consistency of units: encountered a model entity with no declared units. */
, UnrecognisedSBOTerm                   = 99701 /*!< Unrecognized 'sboTerm' attribute value. */
, ObseleteSBOTerm                       = 99702 /*!< Obsolete 'sboTerm' attribute value. */
, IncorrectCompartmentSpatialDimensions = 99901 /*!< In Sed Level 1, only three-dimensional compartments are allowed. */
, CompartmentTypeNotValidAttribute      = 99902 /*!< CompartmentType objects are not available in this Level+Version of Sed. */
, ConstantNotValidAttribute             = 99903 /*!< This Level+Version of Sed does not support the 'constant' attribute on this component. */
, MetaIdNotValidAttribute               = 99904 /*!< Attribute 'metaid' is not available in Sed Level 1. */
, SBOTermNotValidAttributeBeforeL2V3    = 99905 /*!< The 'sboTerm' attribute is not available on this component before Sed Level 2 Version 3. */
, InvalidL1CompartmentUnits             = 99906 /*!< Invalid units for a compartment in Sed Level 1. */
, L1V1CompartmentVolumeReqd             = 99907 /*!< In Sed Level 1, a compartment's volume must be specified. */
, CompartmentTypeNotValidComponent      = 99908 /*!< CompartmentType objects are not available in this Level+Version of Sed. */
, ConstraintNotValidComponent           = 99909 /*!< Constraint objects are not available in this Level+Version of Sed. */
, EventNotValidComponent                = 99910 /*!< Event objects are not available in this Level+Version of Sed. */
, SBOTermNotValidAttributeBeforeL2V2    = 99911 /*!< The 'sboTerm' attribute is invalid for this component before Level 2 Version 2. */
, FuncDefNotValidComponent              = 99912 /*!< FunctionDefinition objects are not available in this Level+Version of Sed. */
, InitialAssignNotValidComponent        = 99913 /*!< InitialAssignment objects are not available in this Level+Version of Sed. */
, VariableNotValidAttribute             = 99914 /*!< Attribute 'variable' is not available on this component in this Level+Version of Sed. */
, UnitsNotValidAttribute                = 99915 /*!< Attribute 'units' is not available on this component in this Level+Version of Sed. */
, ConstantSpeciesNotValidAttribute      = 99916 /*!< Attribute 'constant' is not available on Species objects in Sed Level 1. */
, SpatialSizeUnitsNotValidAttribute     = 99917 /*!< Attribute 'spatialSizeUnits' is not available on Species objects in Sed Level 1. */
, SpeciesTypeNotValidAttribute          = 99918 /*!< Attribute 'speciesType' is not available on Species objects in Sed Level 1. */
, HasOnlySubsUnitsNotValidAttribute     = 99919 /*!< Attribute 'hasOnlySubstanceUnits' is not available on Species objects in Sed Level 1. */
, IdNotValidAttribute                   = 99920 /*!< Attribute 'id' is not available on SpeciesReference objects in Sed Level 1. */
, NameNotValidAttribute                 = 99921 /*!< Attribute 'name' is not available on SpeciesReference objects in Sed Level 1. */
, SpeciesTypeNotValidComponent          = 99922 /*!< The SpeciesType object is not supported in Sed Level 1. */
, StoichiometryMathNotValidComponent    = 99923 /*!< The StoichiometryMath object is not supported in Sed Level 1. */
, MultiplierNotValidAttribute           = 99924 /*!< Attribute 'multiplier' on Unit objects is not supported in Sed Level 1. */
, OffsetNotValidAttribute               = 99925 /*!< Attribute 'offset' on Unit objects is only available in Sed Level 2 Version 1. */
, L3SpatialDimensionsUnset              = 99926 /*!< No value given for 'spatialDimensions' attribute; assuming a value of 3. */
, UnknownCoreAttribute                  = 99994 /*!< Encountered an unknow attribute in core ns */
, UnknownPackageAttribute               = 99995 /*!< Encountered an unknow attribute in package ns  */
, PackageConversionNotSupported         = 99996 /*!< Conversion of Sed Level 3 package constructs is not yet supported. */
, InvalidTargetLevelVersion             = 99997 /*!< The requested Sed Level/Version combination is not known to exist. */
, L3NotSupported                        = 99998 /*!< Sed Level 3 is not yet supported. */
, SedCodesUpperBound                   = 99999
} SedErrorCode_t;


/**
 * Category codes for SedError diagnostics.
 *
 * Note that these are distinct from XMLError's category codes.  User
 * programs receiving an SedError object can use this distinction to
 * check whether the error represents a low-level XML problem or an
 * Sed problem.
 *
 * @see #XMLErrorCategory_t
 */
typedef enum 
{
	LIBSEDML_CAT_INTERNAL,
    LIBSEDML_CAT_SEDML 
    /*!< General Sed error  not falling into another category below. */

  , LIBSEDML_CAT_SEDML_L1_COMPAT
    /*!< Category of errors that can only occur during attempted
     * translation from one Level/Version of Sed to another.  This
     * particular category applies to errors encountered while trying to
     * convert a model from Sed Level&nbsp;2 to Sed Level&nbsp;1. */

  , LIBSEDML_CAT_GENERAL_CONSISTENCY
    /*!< Category of errors that can occur while validating general Sed
     * constructs.  With respect to the Sed specification, these concern
     * failures in applying the validation rules numbered 2xxxx in the
     * Level&nbsp;2 Versions&nbsp;2&ndash;4
     * and Level&nbsp;3 Version&nbsp;1 specifications. */

  , LIBSEDML_CAT_IDENTIFIER_CONSISTENCY
    /*!< Category of errors that can occur while validating symbol
     * identifiers in a model.  With respect to the Sed specification,
     * these concern failures in applying the validation rules numbered
     * 103xx in the Level&nbsp;2 Versions&nbsp;2&ndash;4
     * and Level&nbsp;3 Version&nbsp;1 specifications. */


  , LIBSEDML_CAT_MATHML_CONSISTENCY
    /*!< Category of errors that can occur while validating MathML formulas
     * in a model.  With respect to the Sed specification, these concern
     * failures in applying the validation rules numbered 102xx in the
     * Level&nbsp;2 Versions&nbsp;2&ndash;4
     * and Level&nbsp;3 Version&nbsp;1 specifications. */

  , LIBSEDML_CAT_INTERNAL_CONSISTENCY
    /*!< Category of errors that can occur while validating libSed's 
     * internal representation of Sed constructs. (These are tests 
     * performed by libSed and do not have equivalent Sed validation 
     * rules.)  */


} SedErrorCategory_t;


/**
 * Severity codes for SedError diagnostics.
 *
 * These are distinct from XMLError's severity codes.  
 *
 * @see XMLErrorSeverity_t
 */
typedef enum
{
  /** @cond doxygen-libsbml-internal **/

  /* The following are used internally in SedErrorTable, but publicly,
   * we only report one of the 4 XMLError_Severity values.  Translation
   * of the codes is done in SedError.cpp.
   */
	LIBSEDML_SEV_ERROR = LIBSBML_SEV_ERROR,
	LIBSEDML_SEV_FATAL = LIBSBML_SEV_FATAL,
	LIBSEDML_SEV_WARNING = LIBSBML_SEV_WARNING,
   
    LIBSEDML_SEV_SCHEMA_ERROR    = (LIBSBML_SEV_FATAL + 1)
    /*!< The XML content does not conform to
     * the relevant version of the Sed XML 
     * Schema.  The content is not valid Sed. */

  , LIBSEDML_SEV_GENERAL_WARNING
    /*!< The XML content is invalid for some
     * levels/versions of Sed, and while it
     * may be valid in others, it is something
     * that is best avoided anyway.  LibSed
     * will issue warnings in those cases it
     * can recognize. */

  , LIBSEDML_SEV_NOT_APPLICABLE
    /*!< This error code is only a placeholder
     * for errors that have relevance to some
     * versions of Sed but not others. */

  /** @endcond **/
} SedErrorSeverity_t;

END_C_DECLS
LIBSEDML_CPP_NAMESPACE_END

#ifdef __cplusplus

LIBSEDML_CPP_NAMESPACE_BEGIN

class LIBSEDML_EXTERN SedError : public XMLError
{
public:

  /**
   * Creates a new SedError to report that something occurred during Sed
   * processing.
   *
   * When a libSed operation on Sed content results in a warning, error
   * or other diagnostic, the issue is reported as an SedError object.
   * SedError objects have identification numbers to indicate the nature
   * of the exception.  @if clike These numbers are drawn from
   * the enumeration <a class="el"
   * href="#SedErrorCode_t">
   * SedErrorCode_t</a>.  @endif@if java These numbers are
   * defined as unsigned integer constants in the file
   * "libsbmlConstants.html".  See the <a class="el"
   * href="#SedErrorCode_t">top of this documentation page</a> for a table
   * listing the possible values and their meanings. @endif@if python These
   * numbers are defined as unsigned integer constants in the interface
   * class @link libsbml libsbml@endlink.  See the <a class="el"
   * href="#SedErrorCode_t">top of this documentation page</a> for a table
   * listing the possible values and their meanings. @endif@~ The argument 
   * @p errorId to this constructor @em can be (but does not have to be) a
   * value from this @if clike enumeration. If it @em is a value
   * from <a class="el" href="#SedErrorCode_t">SedErrorCode_t</a>, the
   * SedError class assumes the error is a low-level system or Sed layer
   * error and <em>prepends</em> a built-in, predefined error message to
   * any string passed in the argument @p details to this constructor.  In
   * addition, all <a class="el"
   * href="#SedErrorCode_t">SedErrorCode_t</a> errors have associated
   * values for the @p severity and @p category codes, and these fields are
   * filled-in as well from the enumerations <a class="el"
   * href="#SedErrorSeverity_t">SedErrorSeverity_t</a> and <a class="el"
   * href="#SedErrorCategory_t">SedErrorCategory_t</a>,
   * respectively. @else set of constants.  If it @em
   * is one of the predefined error identifiers, the SedError class
   * assumes the error is a low-level system or Sed layer error and
   * <em>prepends</em> a built-in, predefined error message to any string
   * passed in the argument @p details to this constructor.  In addition,
   * all the predefined error identifiers have associated values for the 
   * @p severity and @p category codes, and these fields are filled-in using
   * the libSed defaults for each different error identifier. @endif@~
   *
   * If the error identifier @p errorId is a number greater than 99999, the
   * SedError class assumes the error was generated from another part of
   * the software and does not do additional filling in of values beyond
   * the default in the constructor itself.  This allows SedError to serve
   * as a base class for other errors, such as for user-defined validation
   * rules (see Validator).  Callers should fill in all the parameters with
   * suitable values if generating errors with codes greater than 99999 to
   * make maximum use of the SedError facilities.
   *
   * @if clike As mentioned above, there are two other
   * enumerations, <a class="el"
   * href="#SedErrorSeverity_t">SedErrorSeverity_t</a> and <a class="el"
   * href="#SedErrorCategory_t">SedErrorCategory_t</a>, used for indicating
   * the severity and category of error for the predefined SedError codes.
   * The values passed in @p severity and @p category override the defaults
   * assigned based on the error code.  If the value of @p errorId is a
   * value from <a class="el" href="#SedErrorCode_t">SedErrorCode_t</a>,
   * callers do not need to fill in @p severity and @p category.
   * Conversely, if @p errorId is not a value from <a class="el"
   * href="#SedErrorCode_t">SedErrorCode_t</a>, callers can use other
   * values (not just those from <a class="el"
   * href="#SedErrorSeverity_t">SedErrorSeverity_t</a> and <a class="el"
   * href="#SedErrorCategory_t">SedErrorCategory_t</a>, but their own
   * special values) for @p severity and 
   * @p category. @else As mentioned above, 
   * there are additional constants defined for <a class="el"
   * href="#SedErrorSeverity_t">standard severity</a> and <a class="el"
   * href="#SedErrorCategory_t">standard category</a> codes, and every predefined 
   * error in libSed has an associated value for severity and category taken
   * from these predefined sets.  These constants have symbol names
   * prefixed with <code>LIBSEDML_SEV_</code> and <code>LIBSEDML_CAT_</code>,
   * respectively.  If the value of @p errorId is one of the standard error
   * codes, callers do not need to fill in @p severity and @p category in a
   * call to this constructor.  Conversely, if @p errorId is not an existing
   * Sed-level error code, callers can use other values for @p severity and
   * @p category. @endif@~
   *
   * Please see the top of the documentation for SedError for a longer
   * discussion of the possible error codes, their meanings, and their
   * applicability to different combinations of Level+Version of Sed.
   *
   * @param errorId an unsigned int, the identification number of the error.
   *
   * @param level the Sed Level of the Sed model
   *
   * @param version the Sed Version within the Level of the Sed model
   * 
   * @param details a string containing additional details about the error.
   * If the error code in @p errorId is one that is recognized by SedError,
   * the given message is @em appended to a predefined message associated
   * with the given code.  If the error code is not recognized, the message
   * is stored as-is as the text of the error.
   * 
   * @param line an unsigned int, the line number at which the error occured.
   * 
   * @param column an unsigned int, the column number at which the error occured.
   * 
   * @param severity an integer indicating severity of the error.
   * 
   * @param category an integer indicating the category to which the error
   * belongs.
   *
   * @param package the Sed Level package involved.
   *
   * @param pkgVersion the version of the @p package.
   *
   * @if notcpp @htmlinclude warn-default-args-in-docs.html @endif@~
   */
  SedError
  (
     const unsigned int errorId  = 0
   , const unsigned int level    =SEDML_DEFAULT_LEVEL
   , const unsigned int version  =SEDML_DEFAULT_VERSION
   , const std::string& details  = ""
   , const unsigned int line     = 0
   , const unsigned int column   = 0
   , const unsigned int severity = LIBSEDML_SEV_ERROR
   , const unsigned int category = LIBSEDML_CAT_SEDML
   , const std::string& package  = "core"
   , const unsigned int pkgVersion = 1
  );


  /**
   * Copy constructor; creates a copy of this SedError.
   */
  SedError(const SedError& orig);


#ifndef SWIG

  /** @cond doxygen-libsbml-internal **/

  /**
   * clone function
   */
  virtual SedError* clone() const; 

  /**
   * Outputs this SedError to stream in the following format (and followed
   * by a newline):
   *
   *   line: (error id) message
   *
   * @param stream the output stream to write to.
   */
  virtual void print(std::ostream& stream) const;

  /** @endcond **/

#endif  /* !SWIG */

protected:
  /** @cond doxygen-libsbml-internal **/

  virtual std::string stringForSeverity(unsigned int code) const;
  virtual std::string stringForCategory(unsigned int code) const;

  void adjustErrorId(unsigned int offset);

  /** @endcond **/
};

LIBSEDML_CPP_NAMESPACE_END

#endif  /* __cplusplus */
#endif /* SedError_h */
