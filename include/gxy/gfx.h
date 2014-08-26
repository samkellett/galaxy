#pragma once

#include <cassert>
#include <functional>

#ifdef GXY_TESTING
#pragma message("Defining mock OpenGL functions")

#include "gxy/macros.h"
#include "gxy/test/functioncallmap.h"

#define GXY_VOID_GL(M, m,ethod) GXY_AUTO_GL(M, m,ethod, void)

#define GXY_AUTO_GL(M, m,ethod, return_type) \
 template <typename... Args> \
 inline return_type m##ethod (Args&&... args) \
 { \
   ++test::function_call_map[GXY_STR( m##ethod )]; \
   return test::function_call_map.default_value<return_type>(GXY_STR( m##ethod )); \
 }

#else
#pragma message("Defining real OpenGL functions")

#include <GLXW/glxw.h>

#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>

#define GXY_VOID_GL(M, m,ethod) \
 template<typename... Args> \
 inline void m##ethod (Args&&... args) \
 { \
   gl##M##ethod (std::forward<Args>(args)...); \
   assert(glGetError() == GL_NO_ERROR); \
 }

#define GXY_AUTO_GL(M, m,ethod, return_type) \
 template<typename... Args> \
 inline return_type m##ethod (Args&&... args) \
 { \
   return_type ret = gl##M##ethod (std::forward<Args>(args)...); \
   assert(glGetError() == GL_NO_ERROR); \
 \
   return ret; \
 }

#endif

namespace gxy {
namespace gl {

// Generated by ./scripts/gl_macros.py
GXY_VOID_GL(A, a,ctiveShaderProgram)
GXY_VOID_GL(A, a,ctiveTexture)
GXY_VOID_GL(A, a,ttachShader)
GXY_VOID_GL(B, b,eginConditionalRender)
GXY_VOID_GL(B, b,eginQuery)
GXY_VOID_GL(B, b,eginQueryIndexed)
GXY_VOID_GL(B, b,eginTransformFeedback)
GXY_VOID_GL(B, b,indAttribLocation)
GXY_VOID_GL(B, b,indBuffer)
GXY_VOID_GL(B, b,indBufferBase)
GXY_VOID_GL(B, b,indBufferRange)
GXY_VOID_GL(B, b,indBuffersBase)
GXY_VOID_GL(B, b,indBuffersRange)
GXY_VOID_GL(B, b,indFragDataLocation)
GXY_VOID_GL(B, b,indFragDataLocationIndexed)
GXY_VOID_GL(B, b,indFramebuffer)
GXY_VOID_GL(B, b,indImageTexture)
GXY_VOID_GL(B, b,indImageTextures)
GXY_VOID_GL(B, b,indProgramPipeline)
GXY_VOID_GL(B, b,indRenderbuffer)
GXY_VOID_GL(B, b,indSampler)
GXY_VOID_GL(B, b,indSamplers)
GXY_VOID_GL(B, b,indTexture)
GXY_VOID_GL(B, b,indTextureUnit)
GXY_VOID_GL(B, b,indTextures)
GXY_VOID_GL(B, b,indTransformFeedback)
GXY_VOID_GL(B, b,indVertexArray)
GXY_VOID_GL(B, b,indVertexBuffer)
GXY_VOID_GL(B, b,indVertexBuffers)
GXY_VOID_GL(B, b,lendColor)
GXY_VOID_GL(B, b,lendEquation)
GXY_VOID_GL(B, b,lendEquationSeparate)
GXY_VOID_GL(B, b,lendEquationSeparatei)
GXY_VOID_GL(B, b,lendEquationSeparateiARB)
GXY_VOID_GL(B, b,lendEquationi)
GXY_VOID_GL(B, b,lendEquationiARB)
GXY_VOID_GL(B, b,lendFunc)
GXY_VOID_GL(B, b,lendFuncSeparate)
GXY_VOID_GL(B, b,lendFuncSeparatei)
GXY_VOID_GL(B, b,lendFuncSeparateiARB)
GXY_VOID_GL(B, b,lendFunci)
GXY_VOID_GL(B, b,lendFunciARB)
GXY_VOID_GL(B, b,litFramebuffer)
GXY_VOID_GL(B, b,litNamedFramebuffer)
GXY_VOID_GL(B, b,ufferData)
GXY_VOID_GL(B, b,ufferPageCommitmentARB)
GXY_VOID_GL(B, b,ufferStorage)
GXY_VOID_GL(B, b,ufferSubData)
GXY_AUTO_GL(C, c,heckFramebufferStatus, GLenum)
GXY_AUTO_GL(C, c,heckNamedFramebufferStatus, GLenum)
GXY_VOID_GL(C, c,lampColor)
GXY_VOID_GL(C, c,lear)
GXY_VOID_GL(C, c,learBufferData)
GXY_VOID_GL(C, c,learBufferSubData)
GXY_VOID_GL(C, c,learBufferfi)
GXY_VOID_GL(C, c,learBufferfv)
GXY_VOID_GL(C, c,learBufferiv)
GXY_VOID_GL(C, c,learBufferuiv)
GXY_VOID_GL(C, c,learColor)
GXY_VOID_GL(C, c,learDepth)
GXY_VOID_GL(C, c,learDepthf)
GXY_VOID_GL(C, c,learNamedBufferData)
GXY_VOID_GL(C, c,learNamedBufferSubData)
GXY_VOID_GL(C, c,learNamedFramebufferfi)
GXY_VOID_GL(C, c,learNamedFramebufferfv)
GXY_VOID_GL(C, c,learNamedFramebufferiv)
GXY_VOID_GL(C, c,learNamedFramebufferuiv)
GXY_VOID_GL(C, c,learStencil)
GXY_VOID_GL(C, c,learTexImage)
GXY_VOID_GL(C, c,learTexSubImage)
GXY_AUTO_GL(C, c,lientWaitSync, GLenum)
GXY_VOID_GL(C, c,lipControl)
GXY_VOID_GL(C, c,olorMask)
GXY_VOID_GL(C, c,olorMaski)
GXY_VOID_GL(C, c,ompileShader)
GXY_VOID_GL(C, c,ompileShaderIncludeARB)
GXY_VOID_GL(C, c,ompressedTexImage1D)
GXY_VOID_GL(C, c,ompressedTexImage2D)
GXY_VOID_GL(C, c,ompressedTexImage3D)
GXY_VOID_GL(C, c,ompressedTexSubImage1D)
GXY_VOID_GL(C, c,ompressedTexSubImage2D)
GXY_VOID_GL(C, c,ompressedTexSubImage3D)
GXY_VOID_GL(C, c,ompressedTextureSubImage1D)
GXY_VOID_GL(C, c,ompressedTextureSubImage2D)
GXY_VOID_GL(C, c,ompressedTextureSubImage3D)
GXY_VOID_GL(C, c,opyBufferSubData)
GXY_VOID_GL(C, c,opyImageSubData)
GXY_VOID_GL(C, c,opyNamedBufferSubData)
GXY_VOID_GL(C, c,opyTexImage1D)
GXY_VOID_GL(C, c,opyTexImage2D)
GXY_VOID_GL(C, c,opyTexSubImage1D)
GXY_VOID_GL(C, c,opyTexSubImage2D)
GXY_VOID_GL(C, c,opyTexSubImage3D)
GXY_VOID_GL(C, c,opyTextureSubImage1D)
GXY_VOID_GL(C, c,opyTextureSubImage2D)
GXY_VOID_GL(C, c,opyTextureSubImage3D)
GXY_VOID_GL(C, c,reateBuffers)
GXY_VOID_GL(C, c,reateFramebuffers)
GXY_AUTO_GL(C, c,reateProgram, GLuint)
GXY_VOID_GL(C, c,reateProgramPipelines)
GXY_VOID_GL(C, c,reateQueries)
GXY_VOID_GL(C, c,reateRenderbuffers)
GXY_VOID_GL(C, c,reateSamplers)
GXY_AUTO_GL(C, c,reateShader, GLuint)
GXY_AUTO_GL(C, c,reateShaderProgramv, GLuint)
GXY_AUTO_GL(C, c,reateSyncFromCLeventARB, GLsync)
GXY_VOID_GL(C, c,reateTextures)
GXY_VOID_GL(C, c,reateTransformFeedbacks)
GXY_VOID_GL(C, c,reateVertexArrays)
GXY_VOID_GL(C, c,ullFace)
GXY_VOID_GL(D, d,ebugMessageCallback)
GXY_VOID_GL(D, d,ebugMessageCallbackARB)
GXY_VOID_GL(D, d,ebugMessageControl)
GXY_VOID_GL(D, d,ebugMessageControlARB)
GXY_VOID_GL(D, d,ebugMessageInsert)
GXY_VOID_GL(D, d,ebugMessageInsertARB)
GXY_VOID_GL(D, d,eleteBuffers)
GXY_VOID_GL(D, d,eleteFramebuffers)
GXY_VOID_GL(D, d,eleteNamedStringARB)
GXY_VOID_GL(D, d,eleteProgram)
GXY_VOID_GL(D, d,eleteProgramPipelines)
GXY_VOID_GL(D, d,eleteQueries)
GXY_VOID_GL(D, d,eleteRenderbuffers)
GXY_VOID_GL(D, d,eleteSamplers)
GXY_VOID_GL(D, d,eleteShader)
GXY_VOID_GL(D, d,eleteSync)
GXY_VOID_GL(D, d,eleteTextures)
GXY_VOID_GL(D, d,eleteTransformFeedbacks)
GXY_VOID_GL(D, d,eleteVertexArrays)
GXY_VOID_GL(D, d,epthFunc)
GXY_VOID_GL(D, d,epthMask)
GXY_VOID_GL(D, d,epthRange)
GXY_VOID_GL(D, d,epthRangeArrayv)
GXY_VOID_GL(D, d,epthRangeIndexed)
GXY_VOID_GL(D, d,epthRangef)
GXY_VOID_GL(D, d,etachShader)
GXY_VOID_GL(D, d,isable)
GXY_VOID_GL(D, d,isableVertexArrayAttrib)
GXY_VOID_GL(D, d,isableVertexAttribArray)
GXY_VOID_GL(D, d,isablei)
GXY_VOID_GL(D, d,ispatchCompute)
GXY_VOID_GL(D, d,ispatchComputeGroupSizeARB)
GXY_VOID_GL(D, d,ispatchComputeIndirect)
GXY_VOID_GL(D, d,rawArrays)
GXY_VOID_GL(D, d,rawArraysIndirect)
GXY_VOID_GL(D, d,rawArraysInstanced)
GXY_VOID_GL(D, d,rawArraysInstancedBaseInstance)
GXY_VOID_GL(D, d,rawBuffer)
GXY_VOID_GL(D, d,rawBuffers)
GXY_VOID_GL(D, d,rawElements)
GXY_VOID_GL(D, d,rawElementsBaseVertex)
GXY_VOID_GL(D, d,rawElementsIndirect)
GXY_VOID_GL(D, d,rawElementsInstanced)
GXY_VOID_GL(D, d,rawElementsInstancedBaseInstance)
GXY_VOID_GL(D, d,rawElementsInstancedBaseVertex)
GXY_VOID_GL(D, d,rawElementsInstancedBaseVertexBaseInstance)
GXY_VOID_GL(D, d,rawRangeElements)
GXY_VOID_GL(D, d,rawRangeElementsBaseVertex)
GXY_VOID_GL(D, d,rawTransformFeedback)
GXY_VOID_GL(D, d,rawTransformFeedbackInstanced)
GXY_VOID_GL(D, d,rawTransformFeedbackStream)
GXY_VOID_GL(D, d,rawTransformFeedbackStreamInstanced)
GXY_VOID_GL(E, e,nable)
GXY_VOID_GL(E, e,nableVertexArrayAttrib)
GXY_VOID_GL(E, e,nableVertexAttribArray)
GXY_VOID_GL(E, e,nablei)
GXY_VOID_GL(E, e,ndConditionalRender)
GXY_VOID_GL(E, e,ndQuery)
GXY_VOID_GL(E, e,ndQueryIndexed)
GXY_VOID_GL(E, e,ndTransformFeedback)
GXY_AUTO_GL(F, f,enceSync, GLsync)
GXY_VOID_GL(F, f,inish)
GXY_VOID_GL(F, f,lush)
GXY_VOID_GL(F, f,lushMappedBufferRange)
GXY_VOID_GL(F, f,lushMappedNamedBufferRange)
GXY_VOID_GL(F, f,ramebufferParameteri)
GXY_VOID_GL(F, f,ramebufferRenderbuffer)
GXY_VOID_GL(F, f,ramebufferTexture)
GXY_VOID_GL(F, f,ramebufferTexture1D)
GXY_VOID_GL(F, f,ramebufferTexture2D)
GXY_VOID_GL(F, f,ramebufferTexture3D)
GXY_VOID_GL(F, f,ramebufferTextureLayer)
GXY_VOID_GL(F, f,rontFace)
GXY_VOID_GL(G, g,enBuffers)
GXY_VOID_GL(G, g,enFramebuffers)
GXY_VOID_GL(G, g,enProgramPipelines)
GXY_VOID_GL(G, g,enQueries)
GXY_VOID_GL(G, g,enRenderbuffers)
GXY_VOID_GL(G, g,enSamplers)
GXY_VOID_GL(G, g,enTextures)
GXY_VOID_GL(G, g,enTransformFeedbacks)
GXY_VOID_GL(G, g,enVertexArrays)
GXY_VOID_GL(G, g,enerateMipmap)
GXY_VOID_GL(G, g,enerateTextureMipmap)
GXY_VOID_GL(G, g,etActiveAtomicCounterBufferiv)
GXY_VOID_GL(G, g,etActiveAttrib)
GXY_VOID_GL(G, g,etActiveSubroutineName)
GXY_VOID_GL(G, g,etActiveSubroutineUniformName)
GXY_VOID_GL(G, g,etActiveSubroutineUniformiv)
GXY_VOID_GL(G, g,etActiveUniform)
GXY_VOID_GL(G, g,etActiveUniformBlockName)
GXY_VOID_GL(G, g,etActiveUniformBlockiv)
GXY_VOID_GL(G, g,etActiveUniformName)
GXY_VOID_GL(G, g,etActiveUniformsiv)
GXY_VOID_GL(G, g,etAttachedShaders)
GXY_AUTO_GL(G, g,etAttribLocation, GLint)
GXY_VOID_GL(G, g,etBooleani_v)
GXY_VOID_GL(G, g,etBooleanv)
GXY_VOID_GL(G, g,etBufferParameteri64v)
GXY_VOID_GL(G, g,etBufferParameteriv)
GXY_VOID_GL(G, g,etBufferPointerv)
GXY_VOID_GL(G, g,etBufferSubData)
GXY_VOID_GL(G, g,etCompressedTexImage)
GXY_VOID_GL(G, g,etCompressedTextureImage)
GXY_VOID_GL(G, g,etCompressedTextureSubImage)
GXY_AUTO_GL(G, g,etDebugMessageLog, GLuint)
GXY_AUTO_GL(G, g,etDebugMessageLogARB, GLuint)
GXY_VOID_GL(G, g,etDoublei_v)
GXY_VOID_GL(G, g,etDoublev)
GXY_AUTO_GL(G, g,etError, GLenum)
GXY_VOID_GL(G, g,etFloati_v)
GXY_VOID_GL(G, g,etFloatv)
GXY_AUTO_GL(G, g,etFragDataIndex, GLint)
GXY_AUTO_GL(G, g,etFragDataLocation, GLint)
GXY_VOID_GL(G, g,etFramebufferAttachmentParameteriv)
GXY_VOID_GL(G, g,etFramebufferParameteriv)
GXY_AUTO_GL(G, g,etGraphicsResetStatus, GLenum)
GXY_AUTO_GL(G, g,etGraphicsResetStatusARB, GLenum)
GXY_AUTO_GL(G, g,etImageHandleARB, GLuint64)
GXY_VOID_GL(G, g,etInteger64i_v)
GXY_VOID_GL(G, g,etInteger64v)
GXY_VOID_GL(G, g,etIntegeri_v)
GXY_VOID_GL(G, g,etIntegerv)
GXY_VOID_GL(G, g,etInternalformati64v)
GXY_VOID_GL(G, g,etInternalformativ)
GXY_VOID_GL(G, g,etMultisamplefv)
GXY_VOID_GL(G, g,etNamedBufferParameteri64v)
GXY_VOID_GL(G, g,etNamedBufferParameteriv)
GXY_VOID_GL(G, g,etNamedBufferPointerv)
GXY_VOID_GL(G, g,etNamedBufferSubData)
GXY_VOID_GL(G, g,etNamedFramebufferAttachmentParameteriv)
GXY_VOID_GL(G, g,etNamedFramebufferParameteriv)
GXY_VOID_GL(G, g,etNamedRenderbufferParameteriv)
GXY_VOID_GL(G, g,etNamedStringARB)
GXY_VOID_GL(G, g,etNamedStringivARB)
GXY_VOID_GL(G, g,etObjectLabel)
GXY_VOID_GL(G, g,etObjectPtrLabel)
GXY_VOID_GL(G, g,etPointerv)
GXY_VOID_GL(G, g,etProgramBinary)
GXY_VOID_GL(G, g,etProgramInfoLog)
GXY_VOID_GL(G, g,etProgramInterfaceiv)
GXY_VOID_GL(G, g,etProgramPipelineInfoLog)
GXY_VOID_GL(G, g,etProgramPipelineiv)
GXY_AUTO_GL(G, g,etProgramResourceIndex, GLuint)
GXY_AUTO_GL(G, g,etProgramResourceLocation, GLint)
GXY_AUTO_GL(G, g,etProgramResourceLocationIndex, GLint)
GXY_VOID_GL(G, g,etProgramResourceName)
GXY_VOID_GL(G, g,etProgramResourceiv)
GXY_VOID_GL(G, g,etProgramStageiv)
GXY_VOID_GL(G, g,etProgramiv)
GXY_VOID_GL(G, g,etQueryIndexediv)
GXY_VOID_GL(G, g,etQueryObjecti64v)
GXY_VOID_GL(G, g,etQueryObjectiv)
GXY_VOID_GL(G, g,etQueryObjectui64v)
GXY_VOID_GL(G, g,etQueryObjectuiv)
GXY_VOID_GL(G, g,etQueryiv)
GXY_VOID_GL(G, g,etRenderbufferParameteriv)
GXY_VOID_GL(G, g,etSamplerParameterIiv)
GXY_VOID_GL(G, g,etSamplerParameterIuiv)
GXY_VOID_GL(G, g,etSamplerParameterfv)
GXY_VOID_GL(G, g,etSamplerParameteriv)
GXY_VOID_GL(G, g,etShaderInfoLog)
GXY_VOID_GL(G, g,etShaderPrecisionFormat)
GXY_VOID_GL(G, g,etShaderSource)
GXY_VOID_GL(G, g,etShaderiv)
GXY_AUTO_GL(G, g,etString, const GLubyte *)
GXY_AUTO_GL(G, g,etStringi, const GLubyte *)
GXY_AUTO_GL(G, g,etSubroutineIndex, GLuint)
GXY_AUTO_GL(G, g,etSubroutineUniformLocation, GLint)
GXY_VOID_GL(G, g,etSynciv)
GXY_VOID_GL(G, g,etTexImage)
GXY_VOID_GL(G, g,etTexLevelParameterfv)
GXY_VOID_GL(G, g,etTexLevelParameteriv)
GXY_VOID_GL(G, g,etTexParameterIiv)
GXY_VOID_GL(G, g,etTexParameterIuiv)
GXY_VOID_GL(G, g,etTexParameterfv)
GXY_VOID_GL(G, g,etTexParameteriv)
GXY_AUTO_GL(G, g,etTextureHandleARB, GLuint64)
GXY_VOID_GL(G, g,etTextureImage)
GXY_VOID_GL(G, g,etTextureLevelParameterfv)
GXY_VOID_GL(G, g,etTextureLevelParameteriv)
GXY_VOID_GL(G, g,etTextureParameterIiv)
GXY_VOID_GL(G, g,etTextureParameterIuiv)
GXY_VOID_GL(G, g,etTextureParameterfv)
GXY_VOID_GL(G, g,etTextureParameteriv)
GXY_AUTO_GL(G, g,etTextureSamplerHandleARB, GLuint64)
GXY_VOID_GL(G, g,etTextureSubImage)
GXY_VOID_GL(G, g,etTransformFeedbackVarying)
GXY_VOID_GL(G, g,etTransformFeedbacki64_v)
GXY_VOID_GL(G, g,etTransformFeedbacki_v)
GXY_VOID_GL(G, g,etTransformFeedbackiv)
GXY_AUTO_GL(G, g,etUniformBlockIndex, GLuint)
GXY_VOID_GL(G, g,etUniformIndices)
GXY_AUTO_GL(G, g,etUniformLocation, GLint)
GXY_VOID_GL(G, g,etUniformSubroutineuiv)
GXY_VOID_GL(G, g,etUniformdv)
GXY_VOID_GL(G, g,etUniformfv)
GXY_VOID_GL(G, g,etUniformiv)
GXY_VOID_GL(G, g,etUniformuiv)
GXY_VOID_GL(G, g,etVertexArrayIndexed64iv)
GXY_VOID_GL(G, g,etVertexArrayIndexediv)
GXY_VOID_GL(G, g,etVertexArrayiv)
GXY_VOID_GL(G, g,etVertexAttribIiv)
GXY_VOID_GL(G, g,etVertexAttribIuiv)
GXY_VOID_GL(G, g,etVertexAttribLdv)
GXY_VOID_GL(G, g,etVertexAttribLui64vARB)
GXY_VOID_GL(G, g,etVertexAttribPointerv)
GXY_VOID_GL(G, g,etVertexAttribdv)
GXY_VOID_GL(G, g,etVertexAttribfv)
GXY_VOID_GL(G, g,etVertexAttribiv)
GXY_VOID_GL(G, g,etnCompressedTexImage)
GXY_VOID_GL(G, g,etnCompressedTexImageARB)
GXY_VOID_GL(G, g,etnTexImage)
GXY_VOID_GL(G, g,etnTexImageARB)
GXY_VOID_GL(G, g,etnUniformdv)
GXY_VOID_GL(G, g,etnUniformdvARB)
GXY_VOID_GL(G, g,etnUniformfv)
GXY_VOID_GL(G, g,etnUniformfvARB)
GXY_VOID_GL(G, g,etnUniformiv)
GXY_VOID_GL(G, g,etnUniformivARB)
GXY_VOID_GL(G, g,etnUniformuiv)
GXY_VOID_GL(G, g,etnUniformuivARB)
GXY_VOID_GL(H, h,int)
GXY_VOID_GL(I, i,nvalidateBufferData)
GXY_VOID_GL(I, i,nvalidateBufferSubData)
GXY_VOID_GL(I, i,nvalidateFramebuffer)
GXY_VOID_GL(I, i,nvalidateNamedFramebufferData)
GXY_VOID_GL(I, i,nvalidateNamedFramebufferSubData)
GXY_VOID_GL(I, i,nvalidateSubFramebuffer)
GXY_VOID_GL(I, i,nvalidateTexImage)
GXY_VOID_GL(I, i,nvalidateTexSubImage)
GXY_AUTO_GL(I, i,sBuffer, GLboolean)
GXY_AUTO_GL(I, i,sEnabled, GLboolean)
GXY_AUTO_GL(I, i,sEnabledi, GLboolean)
GXY_AUTO_GL(I, i,sFramebuffer, GLboolean)
GXY_AUTO_GL(I, i,sImageHandleResidentARB, GLboolean)
GXY_AUTO_GL(I, i,sNamedStringARB, GLboolean)
GXY_AUTO_GL(I, i,sProgram, GLboolean)
GXY_AUTO_GL(I, i,sProgramPipeline, GLboolean)
GXY_AUTO_GL(I, i,sQuery, GLboolean)
GXY_AUTO_GL(I, i,sRenderbuffer, GLboolean)
GXY_AUTO_GL(I, i,sSampler, GLboolean)
GXY_AUTO_GL(I, i,sShader, GLboolean)
GXY_AUTO_GL(I, i,sSync, GLboolean)
GXY_AUTO_GL(I, i,sTexture, GLboolean)
GXY_AUTO_GL(I, i,sTextureHandleResidentARB, GLboolean)
GXY_AUTO_GL(I, i,sTransformFeedback, GLboolean)
GXY_AUTO_GL(I, i,sVertexArray, GLboolean)
GXY_VOID_GL(L, l,ineWidth)
GXY_VOID_GL(L, l,inkProgram)
GXY_VOID_GL(L, l,ogicOp)
GXY_VOID_GL(M, m,akeImageHandleNonResidentARB)
GXY_VOID_GL(M, m,akeImageHandleResidentARB)
GXY_VOID_GL(M, m,akeTextureHandleNonResidentARB)
GXY_VOID_GL(M, m,akeTextureHandleResidentARB)
GXY_VOID_GL(M, m,apBuffer)
GXY_VOID_GL(M, m,apBufferRange)
GXY_VOID_GL(M, m,apNamedBuffer)
GXY_VOID_GL(M, m,apNamedBufferRange)
GXY_VOID_GL(M, m,emoryBarrier)
GXY_VOID_GL(M, m,emoryBarrierByRegion)
GXY_VOID_GL(M, m,inSampleShading)
GXY_VOID_GL(M, m,inSampleShadingARB)
GXY_VOID_GL(M, m,ultiDrawArrays)
GXY_VOID_GL(M, m,ultiDrawArraysIndirect)
GXY_VOID_GL(M, m,ultiDrawArraysIndirectCountARB)
GXY_VOID_GL(M, m,ultiDrawElements)
GXY_VOID_GL(M, m,ultiDrawElementsBaseVertex)
GXY_VOID_GL(M, m,ultiDrawElementsIndirect)
GXY_VOID_GL(M, m,ultiDrawElementsIndirectCountARB)
GXY_VOID_GL(N, n,amedBufferData)
GXY_VOID_GL(N, n,amedBufferPageCommitmentARB)
GXY_VOID_GL(N, n,amedBufferPageCommitmentEXT)
GXY_VOID_GL(N, n,amedBufferStorage)
GXY_VOID_GL(N, n,amedBufferSubData)
GXY_VOID_GL(N, n,amedFramebufferDrawBuffer)
GXY_VOID_GL(N, n,amedFramebufferDrawBuffers)
GXY_VOID_GL(N, n,amedFramebufferParameteri)
GXY_VOID_GL(N, n,amedFramebufferReadBuffer)
GXY_VOID_GL(N, n,amedFramebufferRenderbuffer)
GXY_VOID_GL(N, n,amedFramebufferTexture)
GXY_VOID_GL(N, n,amedFramebufferTextureLayer)
GXY_VOID_GL(N, n,amedRenderbufferStorage)
GXY_VOID_GL(N, n,amedRenderbufferStorageMultisample)
GXY_VOID_GL(N, n,amedStringARB)
GXY_VOID_GL(O, o,bjectLabel)
GXY_VOID_GL(O, o,bjectPtrLabel)
GXY_VOID_GL(P, p,atchParameterfv)
GXY_VOID_GL(P, p,atchParameteri)
GXY_VOID_GL(P, p,auseTransformFeedback)
GXY_VOID_GL(P, p,ixelStoref)
GXY_VOID_GL(P, p,ixelStorei)
GXY_VOID_GL(P, p,ointParameterf)
GXY_VOID_GL(P, p,ointParameterfv)
GXY_VOID_GL(P, p,ointParameteri)
GXY_VOID_GL(P, p,ointParameteriv)
GXY_VOID_GL(P, p,ointSize)
GXY_VOID_GL(P, p,olygonMode)
GXY_VOID_GL(P, p,olygonOffset)
GXY_VOID_GL(P, p,opDebugGroup)
GXY_VOID_GL(P, p,rimitiveRestartIndex)
GXY_VOID_GL(P, p,rogramBinary)
GXY_VOID_GL(P, p,rogramParameteri)
GXY_VOID_GL(P, p,rogramUniform1d)
GXY_VOID_GL(P, p,rogramUniform1dv)
GXY_VOID_GL(P, p,rogramUniform1f)
GXY_VOID_GL(P, p,rogramUniform1fv)
GXY_VOID_GL(P, p,rogramUniform1i)
GXY_VOID_GL(P, p,rogramUniform1iv)
GXY_VOID_GL(P, p,rogramUniform1ui)
GXY_VOID_GL(P, p,rogramUniform1uiv)
GXY_VOID_GL(P, p,rogramUniform2d)
GXY_VOID_GL(P, p,rogramUniform2dv)
GXY_VOID_GL(P, p,rogramUniform2f)
GXY_VOID_GL(P, p,rogramUniform2fv)
GXY_VOID_GL(P, p,rogramUniform2i)
GXY_VOID_GL(P, p,rogramUniform2iv)
GXY_VOID_GL(P, p,rogramUniform2ui)
GXY_VOID_GL(P, p,rogramUniform2uiv)
GXY_VOID_GL(P, p,rogramUniform3d)
GXY_VOID_GL(P, p,rogramUniform3dv)
GXY_VOID_GL(P, p,rogramUniform3f)
GXY_VOID_GL(P, p,rogramUniform3fv)
GXY_VOID_GL(P, p,rogramUniform3i)
GXY_VOID_GL(P, p,rogramUniform3iv)
GXY_VOID_GL(P, p,rogramUniform3ui)
GXY_VOID_GL(P, p,rogramUniform3uiv)
GXY_VOID_GL(P, p,rogramUniform4d)
GXY_VOID_GL(P, p,rogramUniform4dv)
GXY_VOID_GL(P, p,rogramUniform4f)
GXY_VOID_GL(P, p,rogramUniform4fv)
GXY_VOID_GL(P, p,rogramUniform4i)
GXY_VOID_GL(P, p,rogramUniform4iv)
GXY_VOID_GL(P, p,rogramUniform4ui)
GXY_VOID_GL(P, p,rogramUniform4uiv)
GXY_VOID_GL(P, p,rogramUniformHandleui64ARB)
GXY_VOID_GL(P, p,rogramUniformHandleui64vARB)
GXY_VOID_GL(P, p,rogramUniformMatrix2dv)
GXY_VOID_GL(P, p,rogramUniformMatrix2fv)
GXY_VOID_GL(P, p,rogramUniformMatrix2x3dv)
GXY_VOID_GL(P, p,rogramUniformMatrix2x3fv)
GXY_VOID_GL(P, p,rogramUniformMatrix2x4dv)
GXY_VOID_GL(P, p,rogramUniformMatrix2x4fv)
GXY_VOID_GL(P, p,rogramUniformMatrix3dv)
GXY_VOID_GL(P, p,rogramUniformMatrix3fv)
GXY_VOID_GL(P, p,rogramUniformMatrix3x2dv)
GXY_VOID_GL(P, p,rogramUniformMatrix3x2fv)
GXY_VOID_GL(P, p,rogramUniformMatrix3x4dv)
GXY_VOID_GL(P, p,rogramUniformMatrix3x4fv)
GXY_VOID_GL(P, p,rogramUniformMatrix4dv)
GXY_VOID_GL(P, p,rogramUniformMatrix4fv)
GXY_VOID_GL(P, p,rogramUniformMatrix4x2dv)
GXY_VOID_GL(P, p,rogramUniformMatrix4x2fv)
GXY_VOID_GL(P, p,rogramUniformMatrix4x3dv)
GXY_VOID_GL(P, p,rogramUniformMatrix4x3fv)
GXY_VOID_GL(P, p,rovokingVertex)
GXY_VOID_GL(P, p,ushDebugGroup)
GXY_VOID_GL(Q, q,ueryCounter)
GXY_VOID_GL(R, r,eadBuffer)
GXY_VOID_GL(R, r,eadPixels)
GXY_VOID_GL(R, r,eadnPixels)
GXY_VOID_GL(R, r,eadnPixelsARB)
GXY_VOID_GL(R, r,eleaseShaderCompiler)
GXY_VOID_GL(R, r,enderbufferStorage)
GXY_VOID_GL(R, r,enderbufferStorageMultisample)
GXY_VOID_GL(R, r,esumeTransformFeedback)
GXY_VOID_GL(S, s,ampleCoverage)
GXY_VOID_GL(S, s,ampleMaski)
GXY_VOID_GL(S, s,amplerParameterIiv)
GXY_VOID_GL(S, s,amplerParameterIuiv)
GXY_VOID_GL(S, s,amplerParameterf)
GXY_VOID_GL(S, s,amplerParameterfv)
GXY_VOID_GL(S, s,amplerParameteri)
GXY_VOID_GL(S, s,amplerParameteriv)
GXY_VOID_GL(S, s,cissor)
GXY_VOID_GL(S, s,cissorArrayv)
GXY_VOID_GL(S, s,cissorIndexed)
GXY_VOID_GL(S, s,cissorIndexedv)
GXY_VOID_GL(S, s,haderBinary)
GXY_VOID_GL(S, s,haderSource)
GXY_VOID_GL(S, s,haderStorageBlockBinding)
GXY_VOID_GL(S, s,tencilFunc)
GXY_VOID_GL(S, s,tencilFuncSeparate)
GXY_VOID_GL(S, s,tencilMask)
GXY_VOID_GL(S, s,tencilMaskSeparate)
GXY_VOID_GL(S, s,tencilOp)
GXY_VOID_GL(S, s,tencilOpSeparate)
GXY_VOID_GL(T, t,exBuffer)
GXY_VOID_GL(T, t,exBufferRange)
GXY_VOID_GL(T, t,exImage1D)
GXY_VOID_GL(T, t,exImage2D)
GXY_VOID_GL(T, t,exImage2DMultisample)
GXY_VOID_GL(T, t,exImage3D)
GXY_VOID_GL(T, t,exImage3DMultisample)
GXY_VOID_GL(T, t,exPageCommitmentARB)
GXY_VOID_GL(T, t,exParameterIiv)
GXY_VOID_GL(T, t,exParameterIuiv)
GXY_VOID_GL(T, t,exParameterf)
GXY_VOID_GL(T, t,exParameterfv)
GXY_VOID_GL(T, t,exParameteri)
GXY_VOID_GL(T, t,exParameteriv)
GXY_VOID_GL(T, t,exStorage1D)
GXY_VOID_GL(T, t,exStorage2D)
GXY_VOID_GL(T, t,exStorage2DMultisample)
GXY_VOID_GL(T, t,exStorage3D)
GXY_VOID_GL(T, t,exStorage3DMultisample)
GXY_VOID_GL(T, t,exSubImage1D)
GXY_VOID_GL(T, t,exSubImage2D)
GXY_VOID_GL(T, t,exSubImage3D)
GXY_VOID_GL(T, t,extureBarrier)
GXY_VOID_GL(T, t,extureBuffer)
GXY_VOID_GL(T, t,extureBufferRange)
GXY_VOID_GL(T, t,extureParameterIiv)
GXY_VOID_GL(T, t,extureParameterIuiv)
GXY_VOID_GL(T, t,extureParameterf)
GXY_VOID_GL(T, t,extureParameterfv)
GXY_VOID_GL(T, t,extureParameteri)
GXY_VOID_GL(T, t,extureParameteriv)
GXY_VOID_GL(T, t,extureStorage1D)
GXY_VOID_GL(T, t,extureStorage2D)
GXY_VOID_GL(T, t,extureStorage2DMultisample)
GXY_VOID_GL(T, t,extureStorage3D)
GXY_VOID_GL(T, t,extureStorage3DMultisample)
GXY_VOID_GL(T, t,extureSubImage1D)
GXY_VOID_GL(T, t,extureSubImage2D)
GXY_VOID_GL(T, t,extureSubImage3D)
GXY_VOID_GL(T, t,extureView)
GXY_VOID_GL(T, t,ransformFeedbackBufferBase)
GXY_VOID_GL(T, t,ransformFeedbackBufferRange)
GXY_VOID_GL(T, t,ransformFeedbackVaryings)
GXY_VOID_GL(U, u,niform1d)
GXY_VOID_GL(U, u,niform1dv)
GXY_VOID_GL(U, u,niform1f)
GXY_VOID_GL(U, u,niform1fv)
GXY_VOID_GL(U, u,niform1i)
GXY_VOID_GL(U, u,niform1iv)
GXY_VOID_GL(U, u,niform1ui)
GXY_VOID_GL(U, u,niform1uiv)
GXY_VOID_GL(U, u,niform2d)
GXY_VOID_GL(U, u,niform2dv)
GXY_VOID_GL(U, u,niform2f)
GXY_VOID_GL(U, u,niform2fv)
GXY_VOID_GL(U, u,niform2i)
GXY_VOID_GL(U, u,niform2iv)
GXY_VOID_GL(U, u,niform2ui)
GXY_VOID_GL(U, u,niform2uiv)
GXY_VOID_GL(U, u,niform3d)
GXY_VOID_GL(U, u,niform3dv)
GXY_VOID_GL(U, u,niform3f)
GXY_VOID_GL(U, u,niform3fv)
GXY_VOID_GL(U, u,niform3i)
GXY_VOID_GL(U, u,niform3iv)
GXY_VOID_GL(U, u,niform3ui)
GXY_VOID_GL(U, u,niform3uiv)
GXY_VOID_GL(U, u,niform4d)
GXY_VOID_GL(U, u,niform4dv)
GXY_VOID_GL(U, u,niform4f)
GXY_VOID_GL(U, u,niform4fv)
GXY_VOID_GL(U, u,niform4i)
GXY_VOID_GL(U, u,niform4iv)
GXY_VOID_GL(U, u,niform4ui)
GXY_VOID_GL(U, u,niform4uiv)
GXY_VOID_GL(U, u,niformBlockBinding)
GXY_VOID_GL(U, u,niformHandleui64ARB)
GXY_VOID_GL(U, u,niformHandleui64vARB)
GXY_VOID_GL(U, u,niformMatrix2dv)
GXY_VOID_GL(U, u,niformMatrix2fv)
GXY_VOID_GL(U, u,niformMatrix2x3dv)
GXY_VOID_GL(U, u,niformMatrix2x3fv)
GXY_VOID_GL(U, u,niformMatrix2x4dv)
GXY_VOID_GL(U, u,niformMatrix2x4fv)
GXY_VOID_GL(U, u,niformMatrix3dv)
GXY_VOID_GL(U, u,niformMatrix3fv)
GXY_VOID_GL(U, u,niformMatrix3x2dv)
GXY_VOID_GL(U, u,niformMatrix3x2fv)
GXY_VOID_GL(U, u,niformMatrix3x4dv)
GXY_VOID_GL(U, u,niformMatrix3x4fv)
GXY_VOID_GL(U, u,niformMatrix4dv)
GXY_VOID_GL(U, u,niformMatrix4fv)
GXY_VOID_GL(U, u,niformMatrix4x2dv)
GXY_VOID_GL(U, u,niformMatrix4x2fv)
GXY_VOID_GL(U, u,niformMatrix4x3dv)
GXY_VOID_GL(U, u,niformMatrix4x3fv)
GXY_VOID_GL(U, u,niformSubroutinesuiv)
GXY_AUTO_GL(U, u,nmapBuffer, GLboolean)
GXY_AUTO_GL(U, u,nmapNamedBuffer, GLboolean)
GXY_VOID_GL(U, u,seProgram)
GXY_VOID_GL(U, u,seProgramStages)
GXY_VOID_GL(V, v,alidateProgram)
GXY_VOID_GL(V, v,alidateProgramPipeline)
GXY_VOID_GL(V, v,ertexArrayAttribBinding)
GXY_VOID_GL(V, v,ertexArrayAttribFormat)
GXY_VOID_GL(V, v,ertexArrayAttribIFormat)
GXY_VOID_GL(V, v,ertexArrayAttribLFormat)
GXY_VOID_GL(V, v,ertexArrayBindingDivisor)
GXY_VOID_GL(V, v,ertexArrayElementBuffer)
GXY_VOID_GL(V, v,ertexArrayVertexBuffer)
GXY_VOID_GL(V, v,ertexArrayVertexBuffers)
GXY_VOID_GL(V, v,ertexAttrib1d)
GXY_VOID_GL(V, v,ertexAttrib1dv)
GXY_VOID_GL(V, v,ertexAttrib1f)
GXY_VOID_GL(V, v,ertexAttrib1fv)
GXY_VOID_GL(V, v,ertexAttrib1s)
GXY_VOID_GL(V, v,ertexAttrib1sv)
GXY_VOID_GL(V, v,ertexAttrib2d)
GXY_VOID_GL(V, v,ertexAttrib2dv)
GXY_VOID_GL(V, v,ertexAttrib2f)
GXY_VOID_GL(V, v,ertexAttrib2fv)
GXY_VOID_GL(V, v,ertexAttrib2s)
GXY_VOID_GL(V, v,ertexAttrib2sv)
GXY_VOID_GL(V, v,ertexAttrib3d)
GXY_VOID_GL(V, v,ertexAttrib3dv)
GXY_VOID_GL(V, v,ertexAttrib3f)
GXY_VOID_GL(V, v,ertexAttrib3fv)
GXY_VOID_GL(V, v,ertexAttrib3s)
GXY_VOID_GL(V, v,ertexAttrib3sv)
GXY_VOID_GL(V, v,ertexAttrib4Nbv)
GXY_VOID_GL(V, v,ertexAttrib4Niv)
GXY_VOID_GL(V, v,ertexAttrib4Nsv)
GXY_VOID_GL(V, v,ertexAttrib4Nub)
GXY_VOID_GL(V, v,ertexAttrib4Nubv)
GXY_VOID_GL(V, v,ertexAttrib4Nuiv)
GXY_VOID_GL(V, v,ertexAttrib4Nusv)
GXY_VOID_GL(V, v,ertexAttrib4bv)
GXY_VOID_GL(V, v,ertexAttrib4d)
GXY_VOID_GL(V, v,ertexAttrib4dv)
GXY_VOID_GL(V, v,ertexAttrib4f)
GXY_VOID_GL(V, v,ertexAttrib4fv)
GXY_VOID_GL(V, v,ertexAttrib4iv)
GXY_VOID_GL(V, v,ertexAttrib4s)
GXY_VOID_GL(V, v,ertexAttrib4sv)
GXY_VOID_GL(V, v,ertexAttrib4ubv)
GXY_VOID_GL(V, v,ertexAttrib4uiv)
GXY_VOID_GL(V, v,ertexAttrib4usv)
GXY_VOID_GL(V, v,ertexAttribBinding)
GXY_VOID_GL(V, v,ertexAttribDivisor)
GXY_VOID_GL(V, v,ertexAttribFormat)
GXY_VOID_GL(V, v,ertexAttribI1i)
GXY_VOID_GL(V, v,ertexAttribI1iv)
GXY_VOID_GL(V, v,ertexAttribI1ui)
GXY_VOID_GL(V, v,ertexAttribI1uiv)
GXY_VOID_GL(V, v,ertexAttribI2i)
GXY_VOID_GL(V, v,ertexAttribI2iv)
GXY_VOID_GL(V, v,ertexAttribI2ui)
GXY_VOID_GL(V, v,ertexAttribI2uiv)
GXY_VOID_GL(V, v,ertexAttribI3i)
GXY_VOID_GL(V, v,ertexAttribI3iv)
GXY_VOID_GL(V, v,ertexAttribI3ui)
GXY_VOID_GL(V, v,ertexAttribI3uiv)
GXY_VOID_GL(V, v,ertexAttribI4bv)
GXY_VOID_GL(V, v,ertexAttribI4i)
GXY_VOID_GL(V, v,ertexAttribI4iv)
GXY_VOID_GL(V, v,ertexAttribI4sv)
GXY_VOID_GL(V, v,ertexAttribI4ubv)
GXY_VOID_GL(V, v,ertexAttribI4ui)
GXY_VOID_GL(V, v,ertexAttribI4uiv)
GXY_VOID_GL(V, v,ertexAttribI4usv)
GXY_VOID_GL(V, v,ertexAttribIFormat)
GXY_VOID_GL(V, v,ertexAttribIPointer)
GXY_VOID_GL(V, v,ertexAttribL1d)
GXY_VOID_GL(V, v,ertexAttribL1dv)
GXY_VOID_GL(V, v,ertexAttribL1ui64ARB)
GXY_VOID_GL(V, v,ertexAttribL1ui64vARB)
GXY_VOID_GL(V, v,ertexAttribL2d)
GXY_VOID_GL(V, v,ertexAttribL2dv)
GXY_VOID_GL(V, v,ertexAttribL3d)
GXY_VOID_GL(V, v,ertexAttribL3dv)
GXY_VOID_GL(V, v,ertexAttribL4d)
GXY_VOID_GL(V, v,ertexAttribL4dv)
GXY_VOID_GL(V, v,ertexAttribLFormat)
GXY_VOID_GL(V, v,ertexAttribLPointer)
GXY_VOID_GL(V, v,ertexAttribP1ui)
GXY_VOID_GL(V, v,ertexAttribP1uiv)
GXY_VOID_GL(V, v,ertexAttribP2ui)
GXY_VOID_GL(V, v,ertexAttribP2uiv)
GXY_VOID_GL(V, v,ertexAttribP3ui)
GXY_VOID_GL(V, v,ertexAttribP3uiv)
GXY_VOID_GL(V, v,ertexAttribP4ui)
GXY_VOID_GL(V, v,ertexAttribP4uiv)
GXY_VOID_GL(V, v,ertexAttribPointer)
GXY_VOID_GL(V, v,ertexBindingDivisor)
GXY_VOID_GL(V, v,iewport)
GXY_VOID_GL(V, v,iewportArrayv)
GXY_VOID_GL(V, v,iewportIndexedf)
GXY_VOID_GL(V, v,iewportIndexedfv)
GXY_VOID_GL(W, w,aitSync)

} // namespace gl
} // namespace gxy

#undef GXY_VOID_GL
#undef GXY_AUTO_GL
