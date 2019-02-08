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

#include "rendererVI2.h"
// 'export'ed functions from the ispc file:
//#include "rendererVI2_ispc.h"
// ospray core:
#include <ospray/common/Data.h>

/*! _everything_ in the ospray core universe should _always_ be in the
  'ospray' namespace. */
namespace ospray {

  /*! though not required, it is good practice to put any module into
    its own namespace (isnide of ospray:: ). Unlike for the naming of
    library and init function, the naming for this namespace doesn't
    particularlly matter. E.g., 'bilinearPatch', 'module_blp',
    'bilinar_patch' etc would all work equally well. */
  namespace rendererVI2 {


	  void RendererVI2::commit()
	  {
		  Renderer::commit();
	  }

	  void RendererVI2::renderFrame(FrameBuffer &frameBuffer)
	  {
		  currentFrameBuffer = &frameBuffer;
		  currentFrameBuffer->beginFrame();

		  int ntiles = currentFrameBuffer->getTotalTiles();

		  /*tasking::parallel_foreach(
			  tiles.begin(), tiles.end(), [&](Tile &t) { renderTile(t); });*/

		  currentFrameBuffer->endFrame(1.f);
	  }

	  void RendererVI2::renderTile(Tile &tile)
	  {
		  //for (int y = 0; y < tile.size.y; y++) {
			 // for (int x = 0; x < tile.size.x; x += varying_width) {
				//  vboolf valid = (x + lane_index<vint>()) < tile.size.x;
				//  size_t index = tile.indexOf(vec2i(x, y));

				//  // we'll render from black -> white based on array index
				//  vfloat gray = float(index) / float(tile.size.x * tile.size.y);
				//  store(gray, tile.r.data() + index, valid);
				//  store(gray, tile.g.data() + index, valid);
				//  store(gray, tile.b.data() + index, valid);
				//  store(vfloat(1.f), tile.a.data() + index, valid);
			 // }
		  //}
	  }

	  // ::ospray::rendererVI2
	  /*! maybe one of the most important parts of this example: this
	  macro 'registers' the RendererVI2 class under the ospray
	  renderer type name of 'rendererVI2'.

	  It is _this_ name that one can now (assuming the module has
	  been loaded with ospLoadModule(), of course) render	with; i.e.,

	  /// check this .... OSP geom = ospNewRender("bilinear_patches") ;
	  */
	  OSP_REGISTER_RENDERER(RendererVI2, rendererVI2);
	  OSP_REGISTER_RENDERER(RendererVI2, rVI2);

  } 

} // ::ospray
