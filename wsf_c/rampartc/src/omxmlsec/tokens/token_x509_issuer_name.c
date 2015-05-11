/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <oxs_tokens.h>

AXIS2_EXTERN axis2_char_t* AXIS2_CALL
oxs_token_get_issuer_name(
    const axutil_env_t *env,
    axiom_node_t *issuer_name_node)
{
    axis2_char_t *val = NULL;

    /* TODO Verification */
    val = (axis2_char_t*)oxs_axiom_get_node_content(env, issuer_name_node);
    return val;
}

/**
* Creates <ds:X509IssuerName> element
*/
AXIS2_EXTERN axiom_node_t* AXIS2_CALL
oxs_token_build_issuer_name_element(
    const axutil_env_t *env,
    axiom_node_t *parent,
    axis2_char_t* value)
{
    axiom_node_t *issuer_name_node = NULL;
    axiom_element_t *issuer_name_ele = NULL;
    axis2_status_t ret;
    axiom_namespace_t *ns_obj = NULL;

    ns_obj = axiom_namespace_create(env, OXS_DSIG_NS, OXS_DS);

    issuer_name_ele = axiom_element_create(
        env, parent, OXS_NODE_X509_ISSUER_NAME, ns_obj, &issuer_name_node);
    if (!issuer_name_ele)
    {
        AXIS2_LOG_ERROR(env->log, AXIS2_LOG_SI, "[rampart]Error creating X509IssuerName element.");
        axiom_namespace_free(ns_obj, env);
        return NULL;
    }

    if (value)
    {
        ret  = axiom_element_set_text(issuer_name_ele, env, value, issuer_name_node);
    }

    return issuer_name_node;
}

