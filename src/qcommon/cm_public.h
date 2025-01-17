/*
 * Wolfenstein: Enemy Territory GPL Source Code
 * Copyright (C) 1999-2010 id Software LLC, a ZeniMax Media company.
 *
 * ET: Legacy
 * Copyright (C) 2012-2023 ET:Legacy team <mail@etlegacy.com>
 *
 * This file is part of ET: Legacy - http://www.etlegacy.com
 *
 * ET: Legacy is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * ET: Legacy is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with ET: Legacy. If not, see <http://www.gnu.org/licenses/>.
 *
 * In addition, Wolfenstein: Enemy Territory GPL Source Code is also
 * subject to certain additional terms. You should have received a copy
 * of these additional terms immediately following the terms and conditions
 * of the GNU General Public License which accompanied the source code.
 * If not, please request a copy in writing from id Software at the address below.
 *
 * id Software LLC, c/o ZeniMax Media Inc., Suite 120, Rockville, Maryland 20850 USA.
 */
/**
 * @file cm_public.h
 */

#ifndef INCLUDE_CM_PUBLIC_H
#define INCLUDE_CM_PUBLIC_H

#include "qfiles.h"

#include "../renderercommon/tr_types.h"

void CM_LoadMap(const char *name, qboolean clientload, unsigned int *checksum);
void CM_ClearMap(void);

clipHandle_t CM_InlineModel(int index);         // 0 = world, 1 + are bmodels
clipHandle_t CM_TempBoxModel(const vec3_t mins, const vec3_t maxs, qboolean capsule);
void CM_SetTempBoxModelContents(int contents);

void CM_ModelBounds(clipHandle_t model, vec3_t mins, vec3_t maxs);

int CM_NumClusters(void);
int CM_NumInlineModels(void);
char *CM_EntityString(void);

// returns an ORed contents mask
int CM_PointContents(const vec3_t p, clipHandle_t model);
int CM_TransformedPointContents(const vec3_t p, clipHandle_t model, const vec3_t origin, const vec3_t angles);

void CM_BoxTrace(trace_t *results, const vec3_t start, const vec3_t end,
                 const vec3_t mins, const vec3_t maxs,
                 clipHandle_t model, int brushmask, qboolean capsule);
void CM_TransformedBoxTrace(trace_t *results, const vec3_t start, const vec3_t end,
                            const vec3_t mins, const vec3_t maxs,
                            clipHandle_t model, int brushmask,
                            const vec3_t origin, const vec3_t angles, qboolean capsule);

byte *CM_ClusterPVS(int cluster);

int CM_PointLeafnum(const vec3_t p);

// only returns non-solid leafs
// overflow if return listsize and if *lastLeaf != list[listsize-1]
int CM_BoxLeafnums(const vec3_t mins, const vec3_t maxs, int *list,
                   int listsize, int *lastLeaf);

int CM_LeafCluster(int leafnum);
int CM_LeafArea(int leafnum);

void CM_AdjustAreaPortalState(int area1, int area2, qboolean open);
qboolean CM_AreasConnected(int area1, int area2);

int CM_WriteAreaBits(byte *buffer, int area);

// cm_patch.c
void CM_DrawDebugSurface(void (*drawPoly)(int color, int numPoints, float *points));

#endif // #ifndef INCLUDE_CM_PUBLIC_H
