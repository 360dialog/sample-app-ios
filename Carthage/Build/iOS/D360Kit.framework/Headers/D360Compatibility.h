//
//  This file is part of Dialog 360 SDK.
//  See the file LICENSE.txt for copying permission.
//

#pragma once

#if !__has_feature(nullability)
#define nonnull
#define nullable
#define _Nullable
#define _Nonnull
#endif

#ifndef NS_ASSUME_NONNULL_BEGIN
#define NS_ASSUME_NONNULL_BEGIN
#endif

#ifndef NS_ASSUME_NONNULL_END
#define NS_ASSUME_NONNULL_END
#endif

#ifndef NS_SWIFT_NAME
#define NS_SWIFT_NAME(_)
#endif



#if __has_feature(objc_generics)

#define D360_GENERIC_NSARRAY(type) NSArray<type>
#define D360_GENERIC_NSMUTABLEARRAY(type) NSMutableArray<type>

#define D360_GENERIC_NSDICTIONARY(key_type,object_key) NSDictionary<key_type, object_key>
#define D360_GENERIC_NSMUTABLEDICTIONARY(key_type,object_key) NSMutableDictionary<key_type, object_key>

#define D360_GENERIC_NSSET(type) NSSet<type>
#define D360_GENERIC_NSMUTABLESET(type) NSMutableSet<type>

#else

#define D360_GENERIC_NSARRAY(type) NSArray
#define D360_GENERIC_NSMUTABLEARRAY(type) NSMutableArray

#define D360_GENERIC_NSDICTIONARY(key_type,object_key) NSDictionary
#define D360_GENERIC_NSMUTABLEDICTIONARY(key_type,object_key) NSMutableDictionary

#define D360_GENERIC_NSSET(type) NSSet
#define D360_GENERIC_NSMUTABLESET(type) NSSetArray

#endif