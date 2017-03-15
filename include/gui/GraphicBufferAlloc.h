/*
 * Copyright (C) 2012 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_GUI_GRAPHIC_BUFFER_ALLOC_H
#define ANDROID_GUI_GRAPHIC_BUFFER_ALLOC_H

#include <stdint.h>
#include <sys/types.h>

#include <gui/IGraphicBufferAlloc.h>
#include <ui/PixelFormat.h>
#include <utils/Errors.h>

namespace android {

class GraphicBuffer;

/*
 * Concrete implementation of the IGraphicBufferAlloc interface.
 *
 * This can create GraphicBuffer instance across processes. This is mainly used
 * by surfaceflinger.
 */

class GraphicBufferAlloc : public BnGraphicBufferAlloc {
public:
    GraphicBufferAlloc();
    virtual ~GraphicBufferAlloc();
    virtual sp<GraphicBuffer> createGraphicBuffer(uint32_t width,
            uint32_t height, PixelFormat format, uint32_t layerCount,
            uint64_t producerUsage, uint64_t consumerUsage,
            std::string requestorName, status_t* error) override;
};


} // namespace android

#endif // ANDROID_GUI_GRAPHIC_BUFFER_ALLOC_H