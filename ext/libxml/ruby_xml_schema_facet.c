#include "ruby_libxml.h"
#include "ruby_xml_schema_facet.h"

VALUE cXMLSchemaFacet;

static void rxml_schema_facet_free(xmlSchemaFacetPtr xschema_type)
{
  xschema_type = NULL;
  xmlFree(xschema_type);
}

/* START FACET*/

static VALUE rxml_schema_facet_node(VALUE self)
{
  xmlSchemaFacetPtr facet;

  Data_Get_Struct(self, xmlSchemaFacetPtr, facet);

  return rxml_node_wrap(facet->node);
}

static VALUE rxml_schema_facet_value(VALUE self)
{
  xmlSchemaFacetPtr facet;

  Data_Get_Struct(self, xmlSchemaFacetPtr, facet);

  return rb_str_new2(facet->value);
}

VALUE rxml_wrap_schema_facet(xmlSchemaFacetPtr facet)
{
  return Data_Wrap_Struct(cXMLSchemaFacet, NULL, rxml_schema_facet_free, facet);
}

void rxml_init_schema_facet(void)
{
  cXMLSchemaFacet = rb_define_class_under(cXMLSchema, "Facet", rb_cObject);
  rb_define_method(cXMLSchemaFacet, "value", rxml_schema_facet_value, 0);
  rb_define_method(cXMLSchemaFacet, "node", rxml_schema_facet_node, 0);
}