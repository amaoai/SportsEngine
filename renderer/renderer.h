/* ************************************************************************
 *
 * Copyright (C) 2022 Vincent Luo All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * ************************************************************************/

/* Creates on 2022/9/14. */
#pragma once

#include "sports/sportspch.h"
#include "sportswin.h"
#include "buffer/vertexbuf.h"
#include "buffer/indexbuf.h"

enum RenderAPI {
    OpenGL,
    Vulkan,
};

/* 渲染器 */
class SportsRenderer {
public:
    virtual        ~SportsRenderer() {};

    virtual void    BeginNewFrame() = 0;
    virtual void    EndNewFrame() = 0;
    virtual void    SetClearColor(float r, float g, float b, float a) = 0;
    virtual void    ClearColorBuffer() = 0;
    virtual void    DrawFrame() = 0;
};

extern SportsRenderer* SportsCreateRenderer(SportsWindow *pSportsWindow);
extern void SportsDestroyRenderer(SportsRenderer *pSportsRenderer);