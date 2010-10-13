#include <FUi.h>
#include <FWeb.h>
#include <FBase.h>
#include <FApp.h>
#include <FSystem.h>
#include <FUix.h>
#include <FMedia.h>
#include <FGraphics.h>

class badaJS :
	public Osp::App::Application,
	public Osp::System::IScreenEventListener,
	public Osp::Ui::IActionEventListener,
	public Osp::Uix::IMotionEventListener,
	public Osp::Ui::ITextEventListener
{
public:
	// The application must have a factory method that creates an instance of the application.
	static Application* CreateInstance(void);

	void OnDoubleTapDetected(void);
	void OnShakeDetected(Osp::Uix::MotionState motionState);
	void OnSnapDetected(Osp::Uix::MotionSnapType snapType);
	Osp::Uix::Motion* __pMotion;

public:
	badaJS();
	~badaJS();

public:
	// This method is called when the application is on initializing.
	bool OnAppInitializing(Osp::App::AppRegistry& appRegistry);

	// This method is called when the application is on terminating.
	bool OnAppTerminating(Osp::App::AppRegistry& appRegistry, bool forcedTermination = false);

	// Thie method is called when the application is brought to the foreground
	void OnForeground(void);

	// This method is called when the application is sent to the background.
	void OnBackground(void);

	// This method is called when the application has little available memory.
	void OnLowMemory(void);

	// This method is called when the device's battery level is changed.
	void OnBatteryLevelChanged(Osp::System::BatteryLevel batteryLevel);

	void OnActionPerformed(const Osp::Ui::Control& source, int actionId);

	void OnTextValueChangeCanceled(const Osp::Ui::Control& source);
	void OnTextValueChanged(const Osp::Ui::Control& source);

	 //	Called when the screen turns on.
	void OnScreenOn (void);

	 //	Called when the screen turns off.
	void OnScreenOff (void);
	

private:
	result __CreateWebForm(void);

	Osp::Ui::Controls::Form*	__pMainForm;
	Osp::Web::Controls::Web*	__pWeb;

};
