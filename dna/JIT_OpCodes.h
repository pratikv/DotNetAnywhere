// Copyright (c) 2009 DotNetAnywhere
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#if !defined(__JIT_OPCODES_H)
#define __JIT_OPCODES_H

#include "EvalStack.h"

// JIT opcodes may be up to 9 bits long
#define JIT_OPCODE_MAXBITS 9
#define JIT_OPCODE_MAXNUM (1 << JIT_OPCODE_MAXBITS)
//#define JIT_OPCODE_MASK ((1 << JIT_OPCODE_MAXBITS) - 1)
//#define JIT_OPCODE(opCode) ((opCode) & JIT_OPCODE_MASK)
//#define JIT_PARAM(opCode) ((opCode) >> JIT_OPCODE_MAXBITS)

// Note that the exact order of some of these op-codes matters.
// This is due to optimisations where groups of opcodes can be handled together

#define JIT_NOP						0x0
#define JIT_RETURN					0x1
#define JIT_LOAD_I32				0x2
#define JIT_BRANCH					0x3
#define JIT_LOAD_STRING				0x4
#define JIT_CALLVIRT_O				0x5
#define JIT_CALL_NATIVE				0x6
#define JIT_CALL_O					0x7
#define JIT_NEWOBJECT				0x8
#define JIT_LOAD_PARAMLOCAL_ADDR	0x9
#define JIT_CALL_PTR				0xa
#define JIT_BOX_CALLVIRT			0xb
#define JIT_INIT_VALUETYPE			0xc
#define JIT_NEW_VECTOR				0xd
#define JIT_NEWOBJECT_VALUETYPE		0xe
#define JIT_IS_INSTANCE				0xf
#define JIT_LOAD_NULL				0x10
#define JIT_UNBOX2VALUETYPE			0x11
#define JIT_UNBOX2OBJECT			0x12
#define JIT_LOAD_FIELD_ADDR			0x13
#define JIT_DUP_GENERAL				0x14
#define JIT_POP						0x15
#define JIT_STORE_OBJECT_VALUETYPE	0x16
#define JIT_DEREF_CALLVIRT			0x17
#define JIT_STORE_ELEMENT			0x18
#define JIT_LEAVE					0x19
#define JIT_END_FINALLY				0x1a
#define JIT_THROW					0x1b
#define JIT_RETHROW					0x1c
#define JIT_LOADOBJECT				0x1d
#define JIT_LOAD_VECTOR_LEN			0x1e
#define JIT_SWITCH					0x1f
#define JIT_LOAD_ELEMENT_ADDR		0x20
#define JIT_CALL_INTERFACE			0x21
#define JIT_CAST_CLASS				0x22
#define JIT_LOAD_ELEMENT			0x23
#define JIT_LOADFIELD_VALUETYPE		0x24
#define	JIT_LOADFIELD				0x25
#define JIT_LOADFUNCTION			0x26
#define JIT_INVOKE_DELEGATE			0x27
#define JIT_CALL_PINVOKE			0x28
#define JIT_LOAD_I64				0x29
#define JIT_INIT_OBJECT				0x2a
#define JIT_DUP_4					0x2b
#define JIT_DUP_8					0x2c
#define JIT_LOADSTATICFIELDADDRESS_CHECKTYPEINIT	0x2d
#define JIT_POP_4					0x2e
#define JIT_LOAD_F32				0x2f

#define JIT_LOADPARAMLOCAL_TYPEID		0x30
#define JIT_LOADPARAMLOCAL_INT64		(JIT_LOADPARAMLOCAL_TYPEID + EVALSTACK_INT64)
#define JIT_LOADPARAMLOCAL_INT32		(JIT_LOADPARAMLOCAL_TYPEID + EVALSTACK_INT32)
#define JIT_LOADPARAMLOCAL_INTNATIVE	(JIT_LOADPARAMLOCAL_TYPEID + EVALSTACK_INTNATIVE)
//#define JIT_LOADPARAMLOCAL_F			(JIT_LOADPARAMLOCAL_TYPEID + EVALSTACK_F)
#define JIT_LOADPARAMLOCAL_F32			(JIT_LOADPARAMLOCAL_TYPEID + EVALSTACK_F32)
#define JIT_LOADPARAMLOCAL_PTR			(JIT_LOADPARAMLOCAL_TYPEID + EVALSTACK_PTR)
#define JIT_LOADPARAMLOCAL_O			(JIT_LOADPARAMLOCAL_TYPEID + EVALSTACK_O)
//#define JIT_LOADPARAMLOCAL_TRANSPTR		(JIT_LOADPARAMLOCAL_TYPEID + EVALSTACK_TRANSPTR)
#define JIT_LOADPARAMLOCAL_F64			(JIT_LOADPARAMLOCAL_TYPEID + EVALSTACK_F64)
#define JIT_LOADPARAMLOCAL_VALUETYPE	(JIT_LOADPARAMLOCAL_TYPEID + EVALSTACK_VALUETYPE)

#define JIT_STOREPARAMLOCAL_TYPEID		0x38
#define JIT_STOREPARAMLOCAL_INT64		(JIT_STOREPARAMLOCAL_TYPEID + EVALSTACK_INT64)
#define JIT_STOREPARAMLOCAL_INT32		(JIT_STOREPARAMLOCAL_TYPEID + EVALSTACK_INT32)
#define JIT_STOREPARAMLOCAL_INTNATIVE	(JIT_STOREPARAMLOCAL_TYPEID + EVALSTACK_INTNATIVE)
//#define JIT_STOREPARAMLOCAL_F			(JIT_STOREPARAMLOCAL_TYPEID + EVALSTACK_F)
#define JIT_STOREPARAMLOCAL_F32			(JIT_STOREPARAMLOCAL_TYPEID + EVALSTACK_F32)
#define JIT_STOREPARAMLOCAL_PTR			(JIT_STOREPARAMLOCAL_TYPEID + EVALSTACK_PTR)
#define JIT_STOREPARAMLOCAL_O			(JIT_STOREPARAMLOCAL_TYPEID + EVALSTACK_O)
//#define JIT_STOREPARAMLOCAL_TRANSPTR	(JIT_STOREPARAMLOCAL_TYPEID + EVALSTACK_TRANSPTR)
#define JIT_STOREPARAMLOCAL_F64			(JIT_STOREPARAMLOCAL_TYPEID + EVALSTACK_F64)
#define JIT_STOREPARAMLOCAL_VALUETYPE	(JIT_STOREPARAMLOCAL_TYPEID + EVALSTACK_VALUETYPE)

#define JIT_STOREFIELD_TYPEID		0x48
#define JIT_STOREFIELD_INT64		(JIT_STOREFIELD_TYPEID + EVALSTACK_INT64)
#define JIT_STOREFIELD_INT32		(JIT_STOREFIELD_TYPEID + EVALSTACK_INT32)
#define JIT_STOREFIELD_INTNATIVE	(JIT_STOREFIELD_TYPEID + EVALSTACK_INTNATIVE)
//#define JIT_STOREFIELD_F			(JIT_STOREFIELD_TYPEID + EVALSTACK_F)
#define JIT_STOREFIELD_F32			(JIT_STOREFIELD_TYPEID + EVALSTACK_F32)
#define JIT_STOREFIELD_PTR			(JIT_STOREFIELD_TYPEID + EVALSTACK_PTR)
#define JIT_STOREFIELD_O			(JIT_STOREFIELD_TYPEID + EVALSTACK_O)
//#define JIT_STOREFIELD_TRANSPTR		(JIT_STOREFIELD_TYPEID + EVALSTACK_TRANSPTR)
#define JIT_STOREFIELD_F64			(JIT_STOREFIELD_TYPEID + EVALSTACK_F64)
#define JIT_STOREFIELD_VALUETYPE	(JIT_STOREFIELD_TYPEID + EVALSTACK_VALUETYPE)

#define JIT_LOADSTATICFIELD_CHECKTYPEINIT_TYPEID	0x50
#define JIT_LOADSTATICFIELD_CHECKTYPEINIT_INT64		(JIT_LOADSTATICFIELD_CHECKTYPEINIT_TYPEID + EVALSTACK_INT64)
#define JIT_LOADSTATICFIELD_CHECKTYPEINIT_INT32		(JIT_LOADSTATICFIELD_CHECKTYPEINIT_TYPEID + EVALSTACK_INT32)
#define JIT_LOADSTATICFIELD_CHECKTYPEINIT_INTNATIVE	(JIT_LOADSTATICFIELD_CHECKTYPEINIT_TYPEID + EVALSTACK_INTNATIVE)
//#define JIT_LOADSTATICFIELD_CHECKTYPEINIT_F			(JIT_LOADSTATICFIELD_CHECKTYPEINIT_TYPEID + EVALSTACK_F)
#define JIT_LOADSTATICFIELD_CHECKTYPEINIT_F32			(JIT_LOADSTATICFIELD_CHECKTYPEINIT_TYPEID + EVALSTACK_F32)
#define JIT_LOADSTATICFIELD_CHECKTYPEINIT_PTR		(JIT_LOADSTATICFIELD_CHECKTYPEINIT_TYPEID + EVALSTACK_PTR)
#define JIT_LOADSTATICFIELD_CHECKTYPEINIT_O			(JIT_LOADSTATICFIELD_CHECKTYPEINIT_TYPEID + EVALSTACK_O)
//#define JIT_LOADSTATICFIELD_CHECKTYPEINIT_TRANSPTR	(JIT_LOADSTATICFIELD_CHECKTYPEINIT_TYPEID + EVALSTACK_TRANSPTR)
#define JIT_LOADSTATICFIELD_CHECKTYPEINIT_F64			(JIT_LOADSTATICFIELD_CHECKTYPEINIT_TYPEID + EVALSTACK_F64)
#define JIT_LOADSTATICFIELD_CHECKTYPEINIT_VALUETYPE	(JIT_LOADSTATICFIELD_CHECKTYPEINIT_TYPEID + EVALSTACK_VALUETYPE)

#define JIT_LOADSTATICFIELD_TYPEID		0x58
#define JIT_LOADSTATICFIELD_INT64		(JIT_LOADSTATICFIELD_TYPEID + EVALSTACK_INT64)
#define JIT_LOADSTATICFIELD_INT32		(JIT_LOADSTATICFIELD_TYPEID + EVALSTACK_INT32)
#define JIT_LOADSTATICFIELD_INTNATIVE	(JIT_LOADSTATICFIELD_TYPEID + EVALSTACK_INTNATIVE)
//#define JIT_LOADSTATICFIELD_F			(JIT_LOADSTATICFIELD_TYPEID + EVALSTACK_F)
#define JIT_LOADSTATICFIELD_F32			(JIT_LOADSTATICFIELD_TYPEID + EVALSTACK_F32)
#define JIT_LOADSTATICFIELD_PTR			(JIT_LOADSTATICFIELD_TYPEID + EVALSTACK_PTR)
#define JIT_LOADSTATICFIELD_O			(JIT_LOADSTATICFIELD_TYPEID + EVALSTACK_O)
//#define JIT_LOADSTATICFIELD_TRANSPTR	(JIT_LOADSTATICFIELD_TYPEID + EVALSTACK_TRANSPTR)
#define JIT_LOADSTATICFIELD_F64			(JIT_LOADSTATICFIELD_TYPEID + EVALSTACK_F64)
#define JIT_LOADSTATICFIELD_VALUEPTYE	(JIT_LOADSTATICFIELD_TYPEID + EVALSTACK_VALUETYPE)

#define JIT_STORESTATICFIELD_TYPEID		0x60
#define JIT_STORESTATICFIELD_INT64		(JIT_STORESTATICFIELD_TYPEID + EVALSTACK_INT64)
#define JIT_STORESTATICFIELD_INT32		(JIT_STORESTATICFIELD_TYPEID + EVALSTACK_INT32)
#define JIT_STORESTATICFIELD_INTNATIVE	(JIT_STORESTATICFIELD_TYPEID + EVALSTACK_INTNATIVE)
//#define JIT_STORESTATICFIELD_F			(JIT_STORESTATICFIELD_TYPEID + EVALSTACK_F)
#define JIT_STORESTATICFIELD_F32		(JIT_STORESTATICFIELD_TYPEID + EVALSTACK_F32)
#define JIT_STORESTATICFIELD_F64		(JIT_STORESTATICFIELD_TYPEID + EVALSTACK_F64)
#define JIT_STORESTATICFIELD_PTR		(JIT_STORESTATICFIELD_TYPEID + EVALSTACK_PTR)
#define JIT_STORESTATICFIELD_O			(JIT_STORESTATICFIELD_TYPEID + EVALSTACK_O)
//#define JIT_STORESTATICFIELD_TRANSPTR	(JIT_STORESTATICFIELD_TYPEID + EVALSTACK_TRANSPTR)
#define JIT_STORESTATICFIELD_VALUETYPE	(JIT_STORESTATICFIELD_TYPEID + EVALSTACK_VALUETYPE)

#define JIT_BOX_TYPEID		0x68
#define JIT_BOX_INT64		(JIT_BOX_TYPEID + EVALSTACK_INT64)
#define JIT_BOX_INT32		(JIT_BOX_TYPEID + EVALSTACK_INT32)
#define JIT_BOX_INTNATIVE	(JIT_BOX_TYPEID + EVALSTACK_INTNATIVE)
//#define JIT_BOX_F			(JIT_BOX_TYPEID + EVALSTACK_F)
#define JIT_BOX_F32			(JIT_BOX_TYPEID + EVALSTACK_F32)
#define JIT_BOX_PTR			(JIT_BOX_TYPEID + EVALSTACK_PTR)
#define JIT_BOX_O			(JIT_BOX_TYPEID + EVALSTACK_O)
//#define JIT_BOX_TRANSPTR	(JIT_BOX_TYPEID + EVALSTACK_TRANSPTR)
#define JIT_BOX_F64			(JIT_BOX_TYPEID + EVALSTACK_F64)
#define JIT_BOX_VALUETYPE	(JIT_BOX_TYPEID + EVALSTACK_VALUETYPE)

#define JIT_CEQ_I32I32			0x70
#define JIT_CGT_I32I32			0x71
#define JIT_CGT_UN_I32I32		0x72
#define JIT_CLT_I32I32			0x73
#define JIT_CLT_UN_I32I32		0x74

#define JIT_CEQ_I64I64			0x75
#define JIT_CGT_I64I64			0x76
#define JIT_CGT_UN_I64I64		0x77
#define JIT_CLT_I64I64			0x78
#define JIT_CLT_UN_I64I64		0x79

#define JIT_ADD_OVF_I32I32		0x7a
#define JIT_ADD_OVF_UN_I32I32	0x7b
#define JIT_MUL_OVF_I32I32		0x7c
#define JIT_MUL_OVF_UN_I32I32	0x7d
#define JIT_SUB_OVF_I32I32		0x7e
#define JIT_SUB_OVF_UN_I32I32	0x7f
#define JIT_ADD_I32I32			0x80
#define JIT_SUB_I32I32			0x81
#define JIT_MUL_I32I32			0x82
#define JIT_DIV_I32I32			0x83
#define JIT_DIV_UN_I32I32		0x84
#define JIT_REM_I32I32			0x85
#define JIT_REM_UN_I32I32		0x86
#define JIT_AND_I32I32			0x87
#define JIT_OR_I32I32			0x88
#define JIT_XOR_I32I32			0x89

#define JIT_NEG_I32				0x8a
#define JIT_NOT_I32				0x8b
#define JIT_NEG_I64				0x8c
#define JIT_NOT_I64				0x8d

#define JIT_BOX_NULLABLE		0x8e
#define JIT_LOAD_F64			0x8f

#define JIT_BEQ_I32I32			0x90
#define JIT_BGE_I32I32			0x91
#define JIT_BGT_I32I32			0x92
#define JIT_BLE_I32I32			0x93
#define JIT_BLT_I32I32			0x94
#define JIT_BNE_UN_I32I32		0x95
#define JIT_BGE_UN_I32I32		0x96
#define JIT_BGT_UN_I32I32		0x97
#define JIT_BLE_UN_I32I32		0x98
#define JIT_BLT_UN_I32I32		0x99

#define JIT_BEQ_I64I64			0x9a
#define JIT_BGE_I64I64			0x9b
#define JIT_BGT_I64I64			0x9c
#define JIT_BLE_I64I64			0x9d
#define JIT_BLT_I64I64			0x9e
#define JIT_BNE_UN_I64I64		0x9f
#define JIT_BGE_UN_I64I64		0xa0
#define JIT_BGT_UN_I64I64		0xa1
#define JIT_BLE_UN_I64I64		0xa2
#define JIT_BLT_UN_I64I64		0xa3

#define JIT_SHL_I32				0xa8
#define JIT_SHR_I32				0xa9
#define JIT_SHR_UN_I32			0xaa
#define JIT_SHL_I64				0xab
#define JIT_SHR_I64				0xac
#define JIT_SHR_UN_I64			0xad

#define JIT_BRANCH_FALSE		0xae
#define JIT_BRANCH_TRUE			0xaf

#define JIT_LOADTOKEN_BASE		0xb0
#define JIT_LOADTOKEN_TYPE		(JIT_LOADTOKEN_BASE + 0)
#define JIT_LOADTOKEN_METHOD	(JIT_LOADTOKEN_BASE + 1)
#define JIT_LOADTOKEN_FIELD		(JIT_LOADTOKEN_BASE + 2)

#define JIT_LOADINDIRECT_I8		0xb3
#define JIT_LOADINDIRECT_U8		0xb4
#define JIT_LOADINDIRECT_I16	0xb5
#define JIT_LOADINDIRECT_U16	0xb6
#define JIT_LOADINDIRECT_I32	0xb7
#define JIT_LOADINDIRECT_U32	0xb8
#define JIT_LOADINDIRECT_I64	0xb9
#define JIT_LOADINDIRECT_I		0xba
#define JIT_LOADINDIRECT_R32	0xbb
#define JIT_LOADINDIRECT_R64	0xbc
#define JIT_LOADINDIRECT_REF	0xbd

#define JIT_STOREINDIRECT_REF	0xbe
#define JIT_STOREINDIRECT_U8	0xbf
#define JIT_STOREINDIRECT_U16	0xc0
#define JIT_STOREINDIRECT_U32	0xc1
#define JIT_STOREINDIRECT_U64	0xc2
#define JIT_STOREINDIRECT_R32	0xc3
#define JIT_STOREINDIRECT_R64	0xc4

//#define JIT_CONV_SIGNED32		0xc5
//#define JIT_CONV_UNSIGNED32		0xc6
//#define JIT_CONV_INT_I64		0xc7

//#define JIT_CONV_I1				0xc5
//#define JIT_CONV_I2				0xc6
//#define JIT_CONV_I4				0xc7
//#define JIT_CONV_I8				0xc8
//#define JIT_CONV_R4				0xc9
//#define JIT_CONV_R8				0xca
//#define JIT_CONV_U4				0xcb
//#define JIT_CONV_U8				0xcc
//#define JIT_CONV_U2				0xcd
//#define JIT_CONV_U1				0xce
//#define JIT_CONV_I_NATIVE		0xcf
//#define JIT_CONV_U_NATIVE		0xd0

//#define JIT_CONV_OVF_I1			0xd1
//#define JIT_CONV_OVF_U1			0xd2
//#define JIT_CONV_OVF_I2			0xd3
//#define JIT_CONV_OVF_U2			0xd4
//#define JIT_CONV_OVF_I4			0xd5
//#define JIT_CONV_OVF_U4			0xd6
//#define JIT_CONV_OVF_I8			0xd7
//#define JIT_CONV_OVF_U8			0xd8

#define JIT_UNBOX_NULLABLE		0xda

#define JIT_STORE_ELEMENT_32	0xde
#define JIT_STORE_ELEMENT_64	0xdf

#define JIT_LOAD_ELEMENT_I8		0xe0
#define JIT_LOAD_ELEMENT_U8		0xe1
#define JIT_LOAD_ELEMENT_I16	0xe2
#define JIT_LOAD_ELEMENT_U16	0xe3
#define JIT_LOAD_ELEMENT_I32	0xe4
#define JIT_LOAD_ELEMENT_U32	0xe5
#define JIT_LOAD_ELEMENT_I64	0xe6
#define JIT_LOAD_ELEMENT_R32	0xe7
#define JIT_LOAD_ELEMENT_R64	0xe8

#define JIT_ADD_OVF_I64I64		0xea
#define JIT_ADD_OVF_UN_I64I64	0xeb
#define JIT_MUL_OVF_I64I64		0xec
#define JIT_MUL_OVF_UN_I64I64	0xed
#define JIT_SUB_OVF_I64I64		0xee
#define JIT_SUB_OVF_UN_I64I64	0xef
#define JIT_ADD_I64I64			0xf0
#define JIT_SUB_I64I64			0xf1
#define JIT_MUL_I64I64			0xf2
#define JIT_DIV_I64I64			0xf3
#define JIT_DIV_UN_I64I64		0xf4
#define JIT_REM_I64I64			0xf5
#define JIT_REM_UN_I64I64		0xf6
#define JIT_AND_I64I64			0xf7
#define JIT_OR_I64I64			0xf8
#define JIT_XOR_I64I64			0xf9

#define JIT_CEQ_F32F32			0xfa
#define JIT_CGT_F32F32			0xfb
#define JIT_CGT_UN_F32F32		0xfc
#define JIT_CLT_F32F32			0xfd
#define JIT_CLT_UN_F32F32		0xfe

#define JIT_BEQ_F32F32			0xff
#define JIT_BGE_F32F32			0x100
#define JIT_BGT_F32F32			0x101
#define JIT_BLE_F32F32			0x102
#define JIT_BLT_F32F32			0x103
#define JIT_BNE_UN_F32F32		0x104
#define JIT_BGE_UN_F32F32		0x105
#define JIT_BGT_UN_F32F32		0x106
#define JIT_BLE_UN_F32F32		0x107
#define JIT_BLT_UN_F32F32		0x108

#define JIT_ADD_F32F32			0x109
#define JIT_SUB_F32F32			0x10a
#define JIT_MUL_F32F32			0x10b
#define JIT_DIV_F32F32			0x10c
#define JIT_DIV_UN_F32F32		0x10d // Never used
#define JIT_REM_F32F32			0x10e
#define JIT_REM_UN_F32F32		0x10f // Never used

#define JIT_CEQ_F64F64			0x110
#define JIT_CGT_F64F64			0x111
#define JIT_CGT_UN_F64F64		0x112
#define JIT_CLT_F64F64			0x113
#define JIT_CLT_UN_F64F64		0x114

#define JIT_BEQ_F64F64			0x115
#define JIT_BGE_F64F64			0x116
#define JIT_BGT_F64F64			0x117
#define JIT_BLE_F64F64			0x118
#define JIT_BLT_F64F64			0x119
#define JIT_BNE_UN_F64F64		0x11a
#define JIT_BGE_UN_F64F64		0x11b
#define JIT_BGT_UN_F64F64		0x11c
#define JIT_BLE_UN_F64F64		0x11d
#define JIT_BLT_UN_F64F64		0x11e

#define JIT_ADD_F64F64			0x11f
#define JIT_SUB_F64F64			0x120
#define JIT_MUL_F64F64			0x121
#define JIT_DIV_F64F64			0x122
#define JIT_DIV_UN_F64F64		0x123 // Never used
#define JIT_REM_F64F64			0x124
#define JIT_REM_UN_F64F64		0x125 // Never used

#define JIT_LOADPARAMLOCAL_0	0x127 // Load 4-byte param/local at offset 0
#define JIT_LOADPARAMLOCAL_1	0x128 // Load 4-byte param/local at offset 4
#define JIT_LOADPARAMLOCAL_2	0x129 // Load 4-byte param/local at offset 8
#define JIT_LOADPARAMLOCAL_3	0x12a // Load 4-byte param/local at offset 12
#define JIT_LOADPARAMLOCAL_4	0x12b // Load 4-byte param/local at offset 16
#define JIT_LOADPARAMLOCAL_5	0x12c // Load 4-byte param/local at offset 20
#define JIT_LOADPARAMLOCAL_6	0x12d // Load 4-byte param/local at offset 24
#define JIT_LOADPARAMLOCAL_7	0x12e // Load 4-byte param/local at offset 28

#define JIT_STOREPARAMLOCAL_0	0x12f // Store 4-byte param/local at offset 0
#define JIT_STOREPARAMLOCAL_1	0x130 // Store 4-byte param/local at offset 4
#define JIT_STOREPARAMLOCAL_2	0x131 // Store 4-byte param/local at offset 8
#define JIT_STOREPARAMLOCAL_3	0x132 // Store 4-byte param/local at offset 12
#define JIT_STOREPARAMLOCAL_4	0x133 // Store 4-byte param/local at offset 16
#define JIT_STOREPARAMLOCAL_5	0x134 // Store 4-byte param/local at offset 20
#define JIT_STOREPARAMLOCAL_6	0x135 // Store 4-byte param/local at offset 24
#define JIT_STOREPARAMLOCAL_7	0x136 // Store 4-byte param/local at offset 28

#define JIT_LOAD_I4_M1			0x137
#define JIT_LOAD_I4_0			0x138
#define JIT_LOAD_I4_1			0x139
#define JIT_LOAD_I4_2			0x13a

#define JIT_LOADFIELD_4			0x13b

#define JIT_CONV_OFFSET_I32 0
#define JIT_CONV_OFFSET_U32 1
#define JIT_CONV_OFFSET_I64 2
#define JIT_CONV_OFFSET_U64 3
#define JIT_CONV_OFFSET_R32 4
#define JIT_CONV_OFFSET_R64 5

#define JIT_CONV_FROM_I32		0x140
#define JIT_CONV_I32_I32		(JIT_CONV_FROM_I32 + JIT_CONV_OFFSET_I32)
#define JIT_CONV_I32_U32		(JIT_CONV_FROM_I32 + JIT_CONV_OFFSET_U32)
#define JIT_CONV_I32_I64		(JIT_CONV_FROM_I32 + JIT_CONV_OFFSET_I64)
#define JIT_CONV_I32_U64		(JIT_CONV_FROM_I32 + JIT_CONV_OFFSET_U64)
#define JIT_CONV_I32_R32		(JIT_CONV_FROM_I32 + JIT_CONV_OFFSET_R32)
#define JIT_CONV_I32_R64		(JIT_CONV_FROM_I32 + JIT_CONV_OFFSET_R64)

#define JIT_CONV_FROM_U32		0x146
#define JIT_CONV_U32_I32		(JIT_CONV_FROM_U32 + JIT_CONV_OFFSET_I32)
#define JIT_CONV_U32_U32		(JIT_CONV_FROM_U32 + JIT_CONV_OFFSET_U32)
#define JIT_CONV_U32_I64		(JIT_CONV_FROM_U32 + JIT_CONV_OFFSET_I64)
#define JIT_CONV_U32_U64		(JIT_CONV_FROM_U32 + JIT_CONV_OFFSET_U64)
#define JIT_CONV_U32_R32		(JIT_CONV_FROM_U32 + JIT_CONV_OFFSET_R32)
#define JIT_CONV_U32_R64		(JIT_CONV_FROM_U32 + JIT_CONV_OFFSET_R64)

#define JIT_CONV_FROM_I64		0x14c
#define JIT_CONV_I64_I32		(JIT_CONV_FROM_I64 + JIT_CONV_OFFSET_I32)
#define JIT_CONV_I64_U32		(JIT_CONV_FROM_I64 + JIT_CONV_OFFSET_U32)
#define JIT_CONV_I64_I64		(JIT_CONV_FROM_I64 + JIT_CONV_OFFSET_I64) // Not used
#define JIT_CONV_I64_U64		(JIT_CONV_FROM_I64 + JIT_CONV_OFFSET_U64) // Not used
#define JIT_CONV_I64_R32		(JIT_CONV_FROM_I64 + JIT_CONV_OFFSET_R32)
#define JIT_CONV_I64_R64		(JIT_CONV_FROM_I64 + JIT_CONV_OFFSET_R64)

#define JIT_CONV_FROM_U64		0x152
#define JIT_CONV_U64_I32		(JIT_CONV_FROM_U64 + JIT_CONV_OFFSET_I32)
#define JIT_CONV_U64_U32		(JIT_CONV_FROM_U64 + JIT_CONV_OFFSET_U32)
#define JIT_CONV_U64_I64		(JIT_CONV_FROM_U64 + JIT_CONV_OFFSET_I64) // Not used
#define JIT_CONV_U64_U64		(JIT_CONV_FROM_U64 + JIT_CONV_OFFSET_U64) // Not used
#define JIT_CONV_U64_R32		(JIT_CONV_FROM_U64 + JIT_CONV_OFFSET_R32)
#define JIT_CONV_U64_R64		(JIT_CONV_FROM_U64 + JIT_CONV_OFFSET_R64)

#define JIT_CONV_FROM_R32		0x158
#define JIT_CONV_R32_I32		(JIT_CONV_FROM_R32 + JIT_CONV_OFFSET_I32)
#define JIT_CONV_R32_U32		(JIT_CONV_FROM_R32 + JIT_CONV_OFFSET_U32)
#define JIT_CONV_R32_I64		(JIT_CONV_FROM_R32 + JIT_CONV_OFFSET_I64)
#define JIT_CONV_R32_U64		(JIT_CONV_FROM_R32 + JIT_CONV_OFFSET_U64)
#define JIT_CONV_R32_R32		(JIT_CONV_FROM_R32 + JIT_CONV_OFFSET_R32)
#define JIT_CONV_R32_R64		(JIT_CONV_FROM_R32 + JIT_CONV_OFFSET_R64)

#define JIT_CONV_FROM_R64		0x15e
#define JIT_CONV_R64_I32		(JIT_CONV_FROM_R64 + JIT_CONV_OFFSET_I32)
#define JIT_CONV_R64_U32		(JIT_CONV_FROM_R64 + JIT_CONV_OFFSET_U32)
#define JIT_CONV_R64_I64		(JIT_CONV_FROM_R64 + JIT_CONV_OFFSET_I64)
#define JIT_CONV_R64_U64		(JIT_CONV_FROM_R64 + JIT_CONV_OFFSET_U64)
#define JIT_CONV_R64_R32		(JIT_CONV_FROM_R64 + JIT_CONV_OFFSET_R32)
#define JIT_CONV_R64_R64		(JIT_CONV_FROM_R64 + JIT_CONV_OFFSET_R64)


#endif
