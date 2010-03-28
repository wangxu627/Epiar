/**\file			ui_container.h
 * \author			Maoserr
 * \date			Created: Saturday, March 27, 2010
 * \date			Modified: Saturday, March 27, 2010
 * \brief			Container object can contain other widgets.
 */

#ifndef __H_UI_CONTAINER__
#define __H_UI_CONTAINER__

class UIContainer : public Widget {
	public:
		UIContainer( void );
		virtual ~UIContainer( void );

		virtual string GetType( void ) { return string("GenericWidget"); }
		bool IsEmpty( void ){return this->children.empty();}

		virtual bool AddChild( Widget *widget );
		virtual bool DelChild( Widget *widget );
		virtual bool Empty( void );
		virtual bool Reset( void );
		virtual Widget *DetermineMouseFocus( int relx, int rely );

		virtual void Draw( int relx = 0, int rely = 0 );

		// Input events
		virtual bool MouseMotion( int xi, int yi );
		virtual bool MouseLUp( int xi, int yi );
		virtual bool MouseLDown( int xi, int yi );
		virtual bool MouseLRelease( void );
		virtual bool MouseMUp( int xi, int yi );
		virtual bool MouseMDown( int xi, int yi );
		virtual bool MouseMRelease( void );
		virtual bool MouseRUp( int xi, int yi );
		virtual bool MouseRDown( int xi, int yi );
		virtual bool MouseRRelease( void );
		virtual bool MouseWUp( int xi, int yi );
		virtual bool MouseWDown( int xi, int yi );
		virtual bool KeyboardEnter( void );
		virtual bool KeyboardLeave( void );
		virtual bool KeyPress( SDLKey key );

	protected:
		list<Widget *> children;

	private:
		Widget *keyboardFocus;			// remembers which child last had focus
		Widget *mouseHover;				// remember which widget mouse is hovering over
		Widget *lmouseDown,
			*mmouseDown,*rmouseDown;	// remember which widget was clicked on

};

#endif//__H_UI_CONTAINER__
