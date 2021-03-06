
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Auryn_Reflector) {

	ZEPHIR_REGISTER_INTERFACE(Auryn, Reflector, auryn, reflector, auryn_reflector_method_entry);

	return SUCCESS;

}

/**
 * Retrieves ReflectionClass instances, caching them for future retrieval
 *
 * @param string $class
 * @return \ReflectionClass
 */
ZEPHIR_DOC_METHOD(Auryn_Reflector, getClass);

/**
 * Retrieves and caches the constructor (ReflectionMethod) for the specified class
 *
 * @param string $class
 * @return \ReflectionMethod
 */
ZEPHIR_DOC_METHOD(Auryn_Reflector, getCtor);

/**
 * Retrieves and caches an array of constructor parameters for the given class
 *
 * @param string $class
 * @return array[\ReflectionParameter]
 */
ZEPHIR_DOC_METHOD(Auryn_Reflector, getCtorParams);

/**
 * Retrieves the class type-hint from a given ReflectionParameter
 *
 * There is no way to directly access a parameter's type-hint without
 * instantiating a new ReflectionClass instance and calling its getName()
 * method. This method stores the results of this approach so that if
 * the same parameter type-hint or ReflectionClass is needed again we
 * already have it cached.
 *
 * @param \ReflectionFunctionAbstract $function
 * @param \ReflectionParameter $param
 */
ZEPHIR_DOC_METHOD(Auryn_Reflector, getParamTypeHint);

/**
 * Retrieves and caches a reflection for the specified function
 *
 * @param string $functionName
 * @return \ReflectionFunction
 */
ZEPHIR_DOC_METHOD(Auryn_Reflector, getFunction);

/**
 * Retrieves and caches a reflection for the specified class method
 *
 * @param mixed $classNameOrInstance
 * @param string $methodName
 * @return \ReflectionMethod
 */
ZEPHIR_DOC_METHOD(Auryn_Reflector, getMethod);

