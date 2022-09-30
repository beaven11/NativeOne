package com.beaven.nativeone

import android.content.res.AssetManager

class NativeRender {

    companion object {
        // Used to load the 'nativeone' library on application startup.
        init {
            System.loadLibrary("nativeone")
        }
    }

    external fun nativeSurfaceCreate(assetManager: AssetManager)
    external fun nativeSurfaceChange(width: Int, height: Int)
    external fun nativeDrawFrame()
    external fun nativeSetRenderType(sampleCategoryType: Int, renderSampleType: Int)
    external fun nativeOnDestroy()

}