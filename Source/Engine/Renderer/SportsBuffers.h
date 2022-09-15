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

/* Creates on 2022/9/15. */
#ifndef SPORTSENGINE_SPORTSBUFFERS_H
#define SPORTSENGINE_SPORTSBUFFERS_H

/*! @brief 顶点结构缓冲区抽象类（需要各个对应的渲染 API 实现改功能）
 */
class SportsVertexBuffer {
public:
    virtual        ~SportsVertexBuffer() = 0;
    virtual void    Bind() = 0;
    virtual void    UnBind() = 0;
};

/*! @brief 顶点索引结构缓冲区抽象类（需要各个对应的渲染 API 实现改功能）
 */
class SportsIndexBuffer {
public:
    virtual        ~SportsIndexBuffer() = 0;
    virtual void    Bind() = 0;
    virtual void    UnBind() = 0;
};

#endif /* SPORTSENGINE_SPORTSBUFFERS_H */
