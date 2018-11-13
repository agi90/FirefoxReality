/* -*- Mode: C++; tab-width: 20; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef VRBROWSER_SKYBOX_H
#define VRBROWSER_SKYBOX_H

#include "vrb/Forward.h"
#include "vrb/MacroUtils.h"

namespace crow {

class Skybox;
typedef std::shared_ptr<Skybox> SkyboxPtr;

class VRLayerCube;
typedef std::shared_ptr<VRLayerCube> VRLayerCubePtr;

class Skybox {
public:
  static SkyboxPtr Create(vrb::CreationContextPtr aContext, const VRLayerCubePtr& aLayer = nullptr);
  void Load(const vrb::ModelLoaderAndroidPtr& aLoader, const std::string &basePath);
  void SetVisible(bool aVisible);
  void SetTransform(const vrb::Matrix& aTransform);
  void SetTintColor(const vrb::Color& aTintColor);
  vrb::NodePtr GetRoot() const;

  struct State;
  Skybox(State& aState, vrb::CreationContextPtr& aContext);
  ~Skybox();
private:
  State& m;
  Skybox() = delete;
  VRB_NO_DEFAULTS(Skybox)
};

} // namespace crow

#endif // VRBROWSER_SKYBOX_H
