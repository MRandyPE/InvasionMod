#ifndef GLOWSTONETORCH_H_
#define GLOWSTONETORCH_H_

#define GLOWSTONE_TORCH_ID 202
#include <lw.h>
#include "mcpe/tile/TorchTile.h"

class GlowstoneTorch : public TorchTile {
public:
	GlowstoneTorch(int, std::string const&);
};

#endif