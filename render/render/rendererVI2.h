// ======================================================================== //
// Copyright 2009-2018 Intel Corporation                                    //
//                                                                          //
// Licensed under the Apache License, Version 2.0 (the "License");          //
// you may not use this file except in compliance with the License.         //
// You may obtain a copy of the License at                                  //
//                                                                          //
//     http://www.apache.org/licenses/LICENSE-2.0                           //
//                                                                          //
// Unless required by applicable law or agreed to in writing, software      //
// distributed under the License is distributed on an "AS IS" BASIS,        //
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. //
// See the License for the specific language governing permissions and      //
// limitations under the License.                                           //
// ======================================================================== //

#pragma once

/*! \file ospray/render/rendererVI2.h Defines a new ospray renderer
  . */

// ospcomon: vec3f, box3f, etcpp - generic helper stuff
#include "ospcommon/vec.h"
#include "ospcommon/box.h"
// ospray: everything that's related to the ospray ray tracing core
#include "ospray/render/Renderer.h"

#include "../common/Model.h"
#include "../fb/FrameBuffer.h"

/*! _everything_ in the ospray core universe should _always_ be in the
  'ospray' namespace. */
namespace ospray {

  /*! though not required, it is good practice to put any module into
    its own namespace (isnide of ospray:: ). Unlike for the naming of
    library and init function, the naming for this namespace doesn't
    particularlly matter. E.g., 'bilinearPatch', 'module_blp',
    'bilinar_patch' etc would all work equally well. */
  namespace rendererVI2 {
    // import ospcommon component - vec3f etc
    using namespace ospcommon;

	struct RendererVI2 : public Renderer
	{
		RendererVI2::RendererVI2() {}

		virtual void commit() override;

		virtual void renderFrame(FrameBuffer &frameBuffer);

		// this should be overridden by actual renderer implementations
		virtual void renderTile(Tile &tile);

		vec4f backgroundColor{ 0.f };

	protected:
		//Model *currentModel{ nullptr };
		FrameBuffer *currentFrameBuffer{ nullptr };
	};



  } // ::ospray::rendererVI2
} // ::ospray

