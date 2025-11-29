#include "Rendering/RenderingSystem/RenderingSystem.h"

int main() {
	RenderingSystem renderingSystem = RenderingSystem();
    int initResult = renderingSystem.initialize();
    if (initResult) {
        return initResult;
	}

	renderingSystem.renderingLoop();

	renderingSystem.finalize();

    return 0;
}
