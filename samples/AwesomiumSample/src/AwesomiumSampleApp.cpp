/*
 Copyright (c) 2010-2012, Paul Houx - All rights reserved.
 This code is intended for use with the Cinder C++ library: http://libcinder.org

 Redistribution and use in source and binary forms, with or without modification, are permitted provided that
 the following conditions are met:

    * Redistributions of source code must retain the above copyright notice, this list of conditions and
	the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
	the following disclaimer in the documentation and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
 WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 POSSIBILITY OF SUCH DAMAGE.
*/

#include "cinder/Font.h"
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"

#include "awesomium/CinderAwesomium.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class AwesomiumSampleApp : public AppBasic {
public:
	void prepareSettings( Settings *settings );
	
	void setup();
	void shutdown();
	void update();
	void draw();
	
	void resize( ResizeEvent event );
	
	void mouseMove( MouseEvent event );	
	void mouseDown( MouseEvent event );	
	void mouseDrag( MouseEvent event );	
	void mouseUp( MouseEvent event );	
	void mouseWheel( MouseEvent event );	
	
	void keyDown( KeyEvent event );
	void keyUp( KeyEvent event );
private:
	Awesomium::WebCore*		mWebCorePtr;
	Awesomium::WebView*		mWebViewPtr;
	
	gl::Texture				mTexture;

	Font					mFont;
};

void AwesomiumSampleApp::prepareSettings(Settings *settings)
{
	settings->setTitle("Awesomium Sample");
	settings->setWindowSize( 1024, 768 );
}

void AwesomiumSampleApp::setup()
{
	// set Awesomium logging to verbose
	Awesomium::WebConfig cnf;
	cnf.log_level = Awesomium::kLogLevel_Verbose;

	// initialize the Awesomium web engine
	mWebCorePtr = Awesomium::WebCore::Initialize( cnf );

	// create a webview
	mWebViewPtr = mWebCorePtr->CreateWebView( getWindowWidth(), getWindowHeight() );
	mWebViewPtr->LoadURL( Awesomium::WebURL( Awesomium::WSLit( "http://libcinder.org" ) ) );
	mWebViewPtr->Focus();

	// 
	mFont = Font("Verdana", 36.0f);
}

void AwesomiumSampleApp::shutdown()
{
	// properly shutdown Awesomium on exit
	if( mWebViewPtr ) mWebViewPtr->Destroy();
	Awesomium::WebCore::Shutdown();
}

void AwesomiumSampleApp::update()
{
	// update the Awesomium engine
	mWebCorePtr->Update();

	// create or update our OpenGL Texture from the webview
	if( ! mWebViewPtr->IsLoading() && ph::awesomium::isDirty( mWebViewPtr ) ) 
	{
		try {
			// set texture filter to NEAREST if you don't intend to transform (scale, rotate) it
			gl::Texture::Format fmt; 
			fmt.setMagFilter( GL_NEAREST );

			// get the texture using a handy conversion function
			mTexture = ph::awesomium::toTexture( mWebViewPtr, fmt );
		}
		catch( const std::exception &e ) {
			console() << e.what() << std::endl;
		}
	}
}

void AwesomiumSampleApp::draw()
{
	gl::clear(); 

	if( mTexture )
	{
		gl::color( Color::white() );
		gl::draw( mTexture );
	}

	if( mWebViewPtr && mWebViewPtr->IsLoading() )
	{
		int w = getWindowWidth();
		int h = getWindowHeight();
		Vec2f pt(0.5f * w, 0.9f * h);

		gl::enableAlphaBlending();
		gl::drawStringCentered( "Loading, please wait...", pt + Vec2f::one(), Color::black(), mFont );
		gl::drawStringCentered( "Loading, please wait...", pt, Color::white(), mFont );
		gl::disableAlphaBlending();
	}
}

void AwesomiumSampleApp::resize( ResizeEvent event )
{
	// resize webview if window resizes
	if( mWebViewPtr )
		mWebViewPtr->Resize( event.getWidth(), event.getHeight() );
}

void AwesomiumSampleApp::mouseMove( MouseEvent event )
{
	// send mouse events to Awesomium
	ph::awesomium::handleMouseMove( mWebViewPtr, event );
}

void AwesomiumSampleApp::mouseDown( MouseEvent event )
{
	// send mouse events to Awesomium
	ph::awesomium::handleMouseDown( mWebViewPtr, event );
}

void AwesomiumSampleApp::mouseDrag( MouseEvent event )
{
	// send mouse events to Awesomium
	ph::awesomium::handleMouseDrag( mWebViewPtr, event );
}

void AwesomiumSampleApp::mouseUp( MouseEvent event )
{
	// send mouse events to Awesomium
	ph::awesomium::handleMouseUp( mWebViewPtr, event );
}

void AwesomiumSampleApp::mouseWheel( MouseEvent event )
{
	// send mouse events to Awesomium
	ph::awesomium::handleMouseWheel( mWebViewPtr, event );
}

void AwesomiumSampleApp::keyDown( KeyEvent event )
{
	// send key events to Awesomium
	ph::awesomium::handleKeyDown( mWebViewPtr, event );
}

void AwesomiumSampleApp::keyUp( KeyEvent event )
{
	// send key events to Awesomium
	ph::awesomium::handleKeyUp( mWebViewPtr, event );
}

CINDER_APP_BASIC( AwesomiumSampleApp, RendererGl )
