package com.beaven.nativeone

import android.opengl.GLSurfaceView
import android.opengl.GLSurfaceView.RENDERMODE_WHEN_DIRTY
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import com.beaven.nativeone.databinding.ActivityMainBinding
import javax.microedition.khronos.egl.EGLConfig
import javax.microedition.khronos.opengles.GL10

class MainActivity : AppCompatActivity(), GLSurfaceView.Renderer {

    private lateinit var binding: ActivityMainBinding
    private val nativeRender = NativeRender()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)
        with(binding.surfaceGl) {
            setEGLContextClientVersion(3)
            setEGLConfigChooser(8, 8, 8, 8, 16, 8)
            setRenderer(this@MainActivity)
            renderMode = RENDERMODE_WHEN_DIRTY
        }
        nativeRender.nativeSetRenderType(IMyNativeRendererType.SAMPLE_TYPE, IMyNativeRendererType.SAMPLE_TYPE_TRIANGLE2)
    }

    override fun onSurfaceCreated(gl: GL10?, config: EGLConfig?) {
        nativeRender.nativeSurfaceCreate(assets)
    }

    override fun onSurfaceChanged(gl: GL10?, width: Int, height: Int) {
        nativeRender.nativeSurfaceChange(width, height)
    }

    override fun onDrawFrame(gl: GL10?) {
        nativeRender.nativeDrawFrame()
    }

    override fun onDestroy() {
        super.onDestroy()
        nativeRender.nativeOnDestroy()
    }
}