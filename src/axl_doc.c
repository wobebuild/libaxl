/**
 *  LibAxl:  Another XML library
 *  Copyright (C) 2006 Advanced Software Production Line, S.L.
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public License
 *  as published by the Free Software Foundation; either version 2.1 of
 *  the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of 
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this program; if not, write to the Free
 *  Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 *  02111-1307 USA
 *  
 *  You may find a copy of the license under this software is released
 *  at COPYING file. This is LGPL software: you are welcome to
 *  develop proprietary applications using this library without any
 *  royalty or fee but returning back any change, improvement or
 *  addition in the form of source code, project image, documentation
 *  patches, etc. 
 *
 *  For commercial support on build XML enabled solutions contact us:
 *          
 *      Postal address:
 *         Advanced Software Production Line, S.L.
 *         C/ Dr. Michavila N� 14
 *         Coslada 28820 Madrid
 *         Spain
 *
 *      Email address:
 *         info@aspl.es - http://fact.aspl.es
 */

/**
 * @internal
 * @brief XML 1.0 Third edition grammar
 *
 * [1]  document       ::=   prolog element Misc*
 * [2]  Char           ::=   \x9 | \xA | \xD | \x20-\xD7FF | \xE000-\xFFFD | \x10000-\10FFFF
 * [3]  S              ::= ( \x20 | \x9 | \xD | \xA)
 * [4]  NameChar       ::=   Letter | Digit | '.' | '-' | '_' | ':' | CombiningChar | Extender
 * [5]  Name           ::= ( Letter | '_' | ':' |) ( NameChar )*
 * [6]  Names          ::=   Name ( \x20 Name )*
 * [7]  Nmtoken        ::= ( NameChar ) +
 * [8]  Nmtokens       ::=   Nmtoken (\x20 Nmtoken)*
 * [9]  EntityValue    ::=   '"' ( [^%&"] | PEReference | Reference )* '"' | "'" ( [^%&'] ! PEReference | Reference )* "'"
 * [10] AttValue       ::=   '"' ( [^<&"] | Reference)*  '"' | "'" ( [^<&'] | Reference )* "'"
 * [11] SystemLiteral  ::= ( '"' [^"]* '"') | ("'" [^']* "'")
 * [12] PubidLiteral   ::=   '"' PubidChar* '"' | "'" (PubidChar - "'") * "'"
 * [13] PubidChar      ::=   \x20 | \xD | \xA | [a-zA-Z0-9] | [-'()+,./:=?;!*#@$_%]
 * [14] CharData       ::=   [^<&]* - ([^<&]* ']]>' [^<&]*)
 * [15] Comments       ::=   '<!--' ((Char - '-') | ('-' (Char - '-')))* '-->'
 * [16] PI             ::=   '<?' PITarget (S (Char* - (Char* '?<' Char*)))? '?>'
 * [17] PITarget       ::=   Name - (('X' | 'x') ('M' | 'm') | ('L' | 'l'))
 * [18] CDsect         ::=   CDStart CData CDend
 * [19] CDStart        ::=   '<![CDATA['
 * [20] CData          ::=   (Char* - (Char* ']]>' Char*))
 * [21] CDEnd          ::=   ']]>'
 * [22] prolog         ::=   XMLDecl? Misc* (doctypedecl Misc*)?
 * [23] XMLDecl        ::=   '<?xml' VersionInfo EncodingDecl? SDDecl? S? '?>'
 * [24] VersionInfo    ::=   S 'version' Eq ("'" VersionNum "'" | '"' VersionNum '"')
 * [25] Eq             ::=   S? '=' S?
 * [26] VersionNum     ::=   '1.0'
 * [27] Misc           ::=   Comment | PI | S
 * [28] doctypedecl    ::=   '<!DOCTYPE' S Name (S ExternalID)? S? ('[' intSubsect ']' S?)? '>'
 * [28a] DeclSep       ::=   PEReference | S
 * [28b] intSubset     ::=   (markupdecl | DeclSep)*
 * [29] markupdecl     ::=   elementdecl | AttlistDecl | EntityDecl | NotationDecl | PI | Comment
 * [30] extSubset      ::=   TextDecl? extSubsetDecl
 * [31] extSubsetDecl  ::=   ( markupdecl | conditionalSect | DeclSep) *
 * [32] SDDecl          ::=   S 'standalone' Eq (("'" ('yes' | 'no') "'") | ('"'" ('yes' | 'no') '"'))
 * 
 * ** productions 33 through 39 have been removed. It seems that this
 * ** productions were supporting xml:lang stuff that is easily
 * ** supported by using directily the xml standard rather than
 * ** mention it as an special production inside the language.
 *  
 * [39] element        ::=   EmptyElemTag | Stag content ETag
 * [40] Stag           ::=   '<' Name (S Attribute)* S? '>'
 * [41] Attribute      ::=   Name Eq AttValue
 * [42] ETag           ::=   '</' Name S? '>'
 * [43] content        ::=   CharData? ((element | Reference | CDSect | PI | Comment) CharData?)*
 * [44] EmptyElemTag   ::=   '<' Name (S Attribute)* S? '/>'
 * [45] elementdecl    ::=   '<!ELEMENT' S Name S contentspec S? '>' 
 * [46] contentspec    ::=   'EMPTY' | 'ANY' | Mixed | children
 * [47] children       ::=   (choice | seq) ('?' | '*' | '+')? 
 * [48] cp             ::=   (Name | choice | seq) ('?' | '*' | '+')? 
 * [49] choice         ::=   '(' S? cp ( S? '|' S? cp)+ S? ')'
 * [50] seq            ::=   '(' S? cp ( S? ',' S? cp )* S? ')'
 * [51] Mixed          ::=   '(' '#PCDATA' (S? '|' S? Name)* S? ')*' | '(' S? '#PCDATA' S? ')'
 * [52] AttlistDecl    ::=   '<!ATTLIST' S Name AttDef* S? '>'
 * [53] AttDef         ::=   S Name S AttType S DefaultDecl
 * [54] AttType        ::=   Stringtype | TokenizedType | Enumeratedtype
 * [55] StringType     ::=   'CDATA'
 * [56] tokenized      ::=   'ID' | 'IDREF' | 'IDREFS' | 'ENTITY' | 'ENTITIES' | 'NMTOKEN' | 'NMTOKENS'
 * [57] EnumeratedType ::=   NotationType | Enumeration
 * [58] NotationType   ::=   'NOTATION' S '(' S? Name (S? Name (S? '|' S? Name)* S? ')'
 * [59] Enumeration    ::=   '(' S? Nmtoken (S? '|' S? Nmtoken)* S? ')'
 * [60] DefaultDecl    ::=   '#REQUIRED' | '#IMPLIED' | (('#FIXED' S)? AttValue)
 * [61] conditionalSect  ::= includeSect | ignoreSect
 * [62] includeSect    ::= '<![' S? 'INCLUDE S? '[' extSubsetDecl ']]>'
 * [63] ignoreSect     ::=  <![' S? 'IGNORE' S? '[' ignoreSectContents* ']]>'
 * [64] ignoreSectContents ::=  Ignore ('<![' ignoreSectContents ']]>' Ignore) *
 * [65] Ignore         ::=  Char * - (Char * ('<!' | ']]>') Char *)
 * [66] CharRef        ::=  '&#' [0-9]+ ';' | '&#x' [0-9a-FA-F]+ ';'
 * [67] Reference      ::=  EntityRef | CharRef
 * [68] EntityRef      ::=  '&' Name ';'
 * [69] PEReference    ::=  '%' Name ';'
 * [70] EntityDecl     ::=  GEDecl | PEDecl
 * [71] GEDecl         ::=  '<!ENTITY' S Name S EntityDef S? '>'
 * [72] PEDecl         ::=  '<!ENTITY' S '%' S Name S PEDef S? '>'
 * [73] EntityDef      ::=  EntityValue | (ExternalID NDataDecl?)
 * [74] PEDef          ::=  EntityValue | ExternalID
 * [75] ExternalID     ::=  'SYSTEM' S SystemLiteral | 'PUBLIC' S PubidLiteral S SystemLiteral
 * [76] NDataDecl      ::=  S 'NData' S Name
 * [77] TextDecl       ::=  '<?xml' VersionInfo? EncodingDecl S? '?>'
 * [78] extParseEnt    ::=  TextDecl? content
 * [80] EncodingDecl   ::=  S 'encoding' Eq ( '"' EncName '"' | "'" EncName "'" )
 * [81] EncName        ::=  [A-Za-z] ([A-Za-z0-9._] | '-')*
 * [82] NotationalDecl ::=  '<!NOTATION' S Name S (ExternalID | PublicID) S? '>' 
 * [83] PublicID       ::=  'PUBLIC' S PubidLiteral
 * 
 * 
 * 
 */

#include <axl_decl.h>
#include <axl_doc.h>
#include <axl_error.h>
#include <axl_stream.h>

struct _axlDoc {
	char    * encoding;
	axlNode * rootNode;
};

/** 
 * @brief Parse an XML entity that is hold inside the memory pointed
 * by <b>entity</b> and limited by <b>entity_size</b>.
 *
 * The function parses the XML document inside the memory hold inside
 * the given reference. The function returns an XML document,
 * represented by \ref axlDoc.
 *
 * The function, optionall, could report error found inside the given
 * \ref axlError variable. In the case the function returns a NULL
 * value, this variable is filled containing the a textual diagnostic
 * error to be showed to the user interface and an error code.
 * 
 * @param entity The XML document to load.
 *
 * @param entity_size The XML document size to load.
 * 
 * @return A newly allocated Axl Document, that must be deallocated
 * using \ref axl_doc_free, when no longer needed. The function could
 * return NULL if the document is not loaded properly.
 *
 * In the case an error is found while procesing the document, error
 * variable will be filled, if defined. -1 will be returned is
 * received parameter are wrong. -2 will be returned if there some
 * error is found while processing the document.
 */
axlDoc * axl_doc_parse (char * entity, int entity_size, axlError ** error)
{
	axlStream * stream;
	char      * string_aux;
	axlDoc    * doc;
		
	
	/* check for environmental parameters */
	if (entity == NULL) {
		axl_error_new (-1, "Received and empty xml stream.", error);
		return NULL;
	}

	if (entity_size <= 0) {
		axl_error_new (-1, "Received an entity size that is less or equal to 0.", error);
		return NULL;
	}

	/* create the xml stream using provided data */
	stream = axl_stream_new (entity, entity_size);
	doc    = axl_new (axlDoc, 1);

	/* consume spaces */
	AXL_CONSUME_SPACES (stream);
		
	/* check for initial XMLDec (production 23) */
	if (axl_stream_inspect (stream, "<?")) {
		
		/* consume spaces */
		AXL_CONSUME_SPACES (stream);

		if (! axl_stream_inspect (stream, "xml")) {
			axl_error_new (-2, "expected initial <?xml declaration, not found", error);
			axl_stream_free (stream);
			return NULL;
		}
		
		/* consume spaces */
		AXL_CONSUME_SPACES (stream);

		if (! axl_stream_inspect (stream, "version=")) {
			axl_error_new (-2, "expected to find 'version=' declaration, not found", error);
			axl_stream_free (stream);
			return NULL;
		}

		/* consume spaces */
		AXL_CONSUME_SPACES (stream);

		/* check for " or ' */
		if (! axl_stream_inspect_several (stream, 2, "\"1.0\"", "'1.0'")) {
			axl_error_new (-2, "expected to find either \" or ' while procesing version number, not found", error);
			axl_stream_free (stream);
			return NULL;
		}

		/* check for an space */
		AXL_CONSUME_SPACES(stream);

		/* now check for encoding */
		if (axl_stream_inspect_several (stream, 2, "encoding=\"", "encoding='")) {
			/* accept encoding instruction */
			axl_stream_accept (stream);

			/* found encoding instruction */
			string_aux = axl_stream_get_until (stream, NULL, 2, "'", "\"");
			if (string_aux) {
				axl_error_new (-2, "expected encoding value, not found", error);
				axl_stream_free (stream);
				return NULL;
			}

			/* set document encoding */
			doc->encoding = axl_strdup (string_aux);
		}

		/* check for an space */
		AXL_CONSUME_SPACES(stream);

		if (axl_stream_inspect_several, (stream, 2, "standalone=\"", "standalone='")) {
			
		}
		
	}

	return NULL;
}

/** 
 * @brief Gets current axl Document encoding.
 * 
 * @param doc The document where the encoding will be retrieved.
 * 
 * @return A valid \ref axlDoc reference. NULL is returned in the case
 * a NULL \ref axlDoc reference is received. The value returned by
 * this function must not be deallocated.
 */
char   * axl_doc_get_encoding (axlDoc * doc)
{
	/* check parameter received */
	axl_return_val_if_fail (doc, NULL);
	
	return (doc->encoding != NULL) ? doc->encoding : "";
}



