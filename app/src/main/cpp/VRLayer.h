/* -*- Mode: C++; tab-width: 20; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef VR_LAYER_DOT_H
#define VR_LAYER_DOT_H

#include "vrb/MacroUtils.h"
#include "vrb/Forward.h"

#include "Device.h"

#include <memory>
#include <functional>
#include <jni.h>

namespace crow {

class VRLayer;
typedef std::shared_ptr<VRLayer> VRLayerPtr;

class VRLayer {
public:
  enum class LayerType {
    QUAD,
    CUBEMAP,
    EQUIRECTANGULAR
  };

  VRLayer::LayerType GetLayerType() const;
  bool IsDrawRequested() const;
  const vrb::Matrix& GetModelView(device::Eye aEye) const;
  device::Eye GetCurrentEye() const;
  int32_t GetPriority() const;
  const vrb::Color& GetTintColor() const;
  const device::EyeRect& GetTextureRect(device::Eye aEye) const;

  bool ShouldDrawBefore(const VRLayer& aLayer);
  void RequestDraw();
  void ClearRequestDraw();
  void SetModelView(device::Eye aEye, const vrb::Matrix& aModelView);
  void SetCurrentEye(device::Eye aEye);
  void SetPriority(int32_t aPriority);
  void SetTintColor(const vrb::Color& aTintColor);
  void SetTextureRect(device::Eye aEye, const device::EyeRect& aTextureRect);
protected:
  struct State;
  VRLayer(State& aState, LayerType aLayerType);
  virtual ~VRLayer() {};
private:
  State& m;
  VRB_NO_DEFAULTS(VRLayer)
};


class VRLayerQuad;
typedef std::shared_ptr<VRLayerQuad> VRLayerQuadPtr;

class VRLayerQuad: public VRLayer {
public:
  static VRLayerQuadPtr Create(const int32_t aWidth, const int32_t aHeight);
  typedef std::function<void(jobject aSurface, int32_t aWidth, int32_t aHeight)> SurfaceChangeDelegate;
  typedef std::function<void()> ResizeDelegate;

  int32_t GetWidth() const;
  int32_t GetHeight() const;
  float GetWorldWidth() const;
  float GetWorldHeight() const;

  void SetWorldSize(const float aWidth, const float aHeight);
  void Resize(const int32_t aWidth, const int32_t aHeight);
  void SetSurfaceChangeDelegate(const SurfaceChangeDelegate& aDelegate);
  void SetResizeDelegate(const ResizeDelegate& aDelegate);
  void SetSurface(jobject aSurface);
protected:
  struct State;
  VRLayerQuad(State& aState);
  virtual ~VRLayerQuad();
private:
  State& m;
  VRB_NO_DEFAULTS(VRLayerQuad)
};

class VRLayerCube;
typedef std::shared_ptr<VRLayerCube> VRLayerCubePtr;

class VRLayerCube: public VRLayer {
public:
  static VRLayerCubePtr Create(const int32_t aWidth, const int32_t aHeight);
  typedef std::function<void(uint32_t aTextureHandle, int32_t aWidth, int32_t aHeight)> TextureChangeDelegate;

  int32_t GetWidth() const;
  int32_t GetHeight() const;
  bool IsLoaded() const;


  void SetTextureChangeDelegate(const TextureChangeDelegate& aDelegate);
  void SetTextureHandle(uint32_t aTextureHandle);
  void SetLoaded(bool aReady);
protected:
  struct State;
  VRLayerCube(State& aState);
  virtual ~VRLayerCube();
private:
  State& m;
  VRB_NO_DEFAULTS(VRLayerCube)
};

} // namespace crow

#endif //  VR_LAYER_DOT_H
