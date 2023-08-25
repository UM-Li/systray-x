#ifndef PREFERENCES_H
#define PREFERENCES_H

/*
 *	Local includes
 */

/*
 *	Qt includes
 */
#include <QObject>
#include <QString>
#include <QStringList>
#include <QByteArray>
#include <QMargins>

/**
 * @brief The Preferences class. Class to hold the preferences.
 */
class Preferences : public QObject
{
    Q_OBJECT

    public:

        /*
         *  Close types
         */
        enum CloseType {
            PREF_DEFAULT_CLOSE_WINDOWS = 0,
            PREF_MINIMIZE_MAIN_TRAY_CLOSE_CHILDREN_WINDOWS,
            PREF_MINIMIZE_ALL_WINDOWS_TRAY,
            PREF_MINIMIZE_MAIN_CLOSE_CHILDREN_WINDOWS,
            PREF_MINIMIZE_ALL_WINDOWS
        };

        /*
         *  Minimize types
         */
        enum MinimizeType {
            PREF_DEFAULT_MINIMIZE = 0,
            PREF_MINIMIZE_METHOD_1,
            PREF_MINIMIZE_METHOD_2
        };

        /*
         *  Minimize icon types
         */
        enum MinimizeIconType {
            PREF_DEFAULT_MINIMIZE_ICON = 0,
            PREF_MINIMIZE_TRAY_ICON
        };

        enum DefaultIconType {
            PREF_DEFAULT_ICON_DEFAULT = 0,
            PREF_DEFAULT_ICON_HIDE,
            PREF_DEFAULT_ICON_CUSTOM
        };

        /*
         *  Icon types
         */
        enum IconType {
            PREF_BLANK_ICON = 0,
            PREF_NEWMAIL_ICON,
            PREF_CUSTOM_ICON,
            PREF_NO_ICON,
            PREF_TB_ICON
        };

        /*
         *  Count types
         */
        enum CountType {
            PREF_COUNT_UNREAD = 0,
            PREF_COUNT_NEW
        };

        enum Theme {
            PREF_THEME_LIGHT = 0,
            PREF_THEME_DARK
        };

        /*
         *  Window states
         */
        enum WindowState {
            STATE_UNKNOWN = 0,
            STATE_NORMAL,
            STATE_MINIMIZED,
            STATE_MAXIMIZED,
            STATE_FULLSCREEN,
            STATE_DOCKED,
            STATE_MINIMIZED_ALL,
            STATE_MINIMIZED_ALL_STARTUP,
        };

        static const QString   STATE_NORMAL_STR;
        static const QString   STATE_MINIMIZED_STR;
        static const QString   STATE_MAXIMIZED_STR;
        static const QString   STATE_FULLSCREEN_STR;
        static const QString   STATE_DOCKED_STR;
        static const QString   STATE_MINIMIZED_ALL_STR;
        static const QString   STATE_MINIMIZED_ALL_STARTUP_STR;

        static const QStringList  WindowStateString;

    public:

        /**
         * @brief Preferences.  Constructor. Destructor.
         */
        Preferences( QObject *parent = nullptr );

        /**
         * @brief getAppPrefChanged. Control for sending changes to the add-on.
         *
         * @return      The state
         */
        bool getAppPrefChanged() const;

        /**
         * @brief setAppPrefChanged. Control for sending changes to the add-on.
         *
         *  @param state    The state
         */
        void setAppPrefChanged( bool state );

        /**
         * @brief setPlatformOs. Set the platform OS.
         *
         *  @param os   The platform os.
         */
        void setPlatformOs( const QString os );

        /**
         * @brief setPlatformArch. Set the platform architecture.
         *
         *  @param arch     The architecture.
         */
        void setPlatformArch( const QString arch );

        /**
         * @brief setPlatformNaclArch. Set the native platform architecture.
         *
         *  @param nacl_arch    The native architecture.
         */
        void setPlatformNaclArch( const QString nacl_arch );

        /**
         * @brief setBrowserName. Set the browser name.
         *
         *  @param name     The name.
         */
        void setBrowserName( const QString name );

        /**
         * @brief setBrowserVendor. Set the browser vendor.
         *
         *  @param vendor   The vendor.
         */
        void setBrowserVendor( const QString vendor );

        /**
         * @brief getBrowserVersion. Get the browser version.
         *
         * @return      The browser version.
         */
        const QString& getBrowserVersion() const;

        /**
         * @brief setBrowserVersion. Set the browser version.
         *
         *  @param version  The version.
         */
        void setBrowserVersion( const QString version );

        /**
         * @brief setBrowserBuildID. set the build id.
         *
         *  @param buildID  The id.
         */
        void setBrowserBuildID( const QString buildID );

        /**
         * @brief getDefaultIconType. Get the default icon type.
         *
         * @return      The icon type.
         */
        DefaultIconType getDefaultIconType() const;

        /**
         * @brief setDefaultIconType. Set the default icon type.
         *
         * @param icon_type     The icon type.
         */
        void setDefaultIconType( DefaultIconType icon_type );

        /**
         * @brief getDefaultIconMime. Get the default icon mime.
         *
         * @return      The icon mime.
         */
        const QString& getDefaultIconMime() const;

        /**
         * @brief setDefaultIconMime. Set the default icon mime.
         *
         * @param icon_mime     The icon mime.
         */
        void setDefaultIconMime( const QString& icon_mime );

        /**
         * @brief getDefaultIconData. Get the default icon data.
         *
         * @return      The icon data.
         */
        const QByteArray& getDefaultIconData() const;

        /**
         * @brief setDefaultIconData. Set the default icon data.
         *
         * @param icon_data     The icon data.
         */
        void setDefaultIconData( const QByteArray& icon_data );

        /**
         * @brief getHideDefaultIcon. Get the hide default icon state.
         *
         * @return      The state.
         */
        bool    getHideDefaultIcon() const;

        /**
         * @brief setHideDefaultIcon. Set the hide default icon state.
         *
         * @param hide  The state.
         */
        void setHideDefaultIcon( bool hide );

        /**
         * @brief getIconType. Get the icon type.
         *
         * @return      The icon type.
         */
        IconType getIconType() const;

        /**
         * @brief setIconType. Set the icon type.
         *
         * @param icon_type     The icon type.
         */
        void setIconType( IconType icon_type );

        /**
         * @brief getIconMime. Get the icon mime.
         *
         * @return      The icon mime.
         */
        const QString& getIconMime() const;

        /**
         * @brief setIconMime. Set the icon mime.
         *
         * @param icon_mime     The icon mime.
         */
        void setIconMime( const QString& icon_mime );

        /**
         * @brief getIconData. Get the icon data.
         *
         * @return      The icon data.
         */
        const QByteArray& getIconData() const;

        /**
         * @brief setIconData. Set the icon data.
         *
         * @param icon_data     The icon data.
         */
        void setIconData( const QByteArray& icon_data );

        /**
         * @brief getShowNumber. Get the show number state.
         *
         * @return      The state.
         */
        bool getShowNumber() const;

        /**
         * @brief setShowNumber. Set the show number state.
         *
         * @param state     The state.
         */
        void setShowNumber( bool state );

        /**
         * @brief getNumberColor. Get the number color.
         *
         * @return      The color.
         */
        QString getNumberColor() const;

        /**
         * @brief setNumberColor. Set the number color.
         *
         * @param color     The color.
         */
        void setNumberColor( QString color );

        /**
         * @brief getNumberSize. Get the number size.
         *
         * @return      The size.
         */
        int getNumberSize() const;

        /**
         * @brief setNumberSize. Set the number size.
         *
         * @param size      The size.
         */
        void setNumberSize( int size );

        /**
         * @brief getNumberAlignment. Get the number alignment.
         *
         * @return      The alignment.
         */
        int getNumberAlignment() const;

        /**
         * @brief setumberAlignment. Set the number alignment.
         *
         * @param alignment     The alignment.
         */
        void setNumberAlignment( int alignment );

        /**
         * @brief getNumberMargins. Get the number margins.
         *
         * @return      The margins.
         */
        QMargins getNumberMargins() const;

        /**
         * @brief setNumberMargins. Set the number margins.
         *
         * @param margins   The margins.
         */
        void setNumberMargins( QMargins margins );

        /**
         * @brief getCountType. Get the count type.
         *
         * @return      The count type.
         */
        CountType getCountType() const;

        /**
         * @brief setCountType. Set the count type.
         *
         * @param count_type    The count type.
         */
        void setCountType( CountType count_type );

        /**
         * @brief getStartupDelay. Get the startup delay.
         *
         * @return      The delay.
         */
        int getStartupDelay() const;

        /**
         * @brief setStartupDelay. Set the startup delay.
         *
         * @param delay     The size.
         */
        void setStartupDelay( int delay );

        /**
         * @brief getMinimizeType. Get the minimize type.
         *
         * @return      The minimize type.
         */
        MinimizeType getMinimizeType() const;

        /**
         * @brief setMinimizeType. Set the minimize type.
         *
         * @param minimize_type     The minimize type.
         */
        void setMinimizeType( MinimizeType minimize_type );

        /**
         * @brief getMinimizeIconType. Get the minimize icon type.
         *
         * @return      The minimize icon type.
         */
        MinimizeIconType getMinimizeIconType() const;

        /**
         * @brief setMinimizeType. Set the minimize icon type.
         *
         * @param minimize_icon_type     The minimize icon type.
         */
        void setMinimizeIconType( MinimizeIconType minimize_icon_type );

        /**
         * @brief getStartMinimized. Get the start minimized state.
         *
         * @return      The state.
         */
        bool getStartMinimized() const;

        /**
         * @brief setStartMinimized. Set the start minimized state.
         *
         * @param state     The state.
         */
        void setStartMinimized( bool state );

        /**
         * @brief getRestoreWindowPositions. Get the restore window positions state.
         *
         * @return      The state.
         */
        bool getRestoreWindowPositions() const;

        /**
         * @brief setRestoreWindowPositions. Set the restore window positions state.
         *
         * @param state     The state.
         */
        void setRestoreWindowPositions( bool state );

        /**
         * @brief getCloseType. Get the close type.
         *
         * @return      The state.
         */
        CloseType   getCloseType() const;

        /**
         * @brief setCloseType. Set the close type.
         *
         * @param close_type    The close type.
         */
        void setCloseType( CloseType close_type );

        /**
         * @brief getTheme. Get the theme state.
         *
         * @return      The state.
         */
        Theme getTheme() const;

        /**
         * @brief setTheme. Set the theme state.
         *
         * @param theme     The state.
         */
        void setTheme( Theme theme );

        /**
         * @brief getStartApp. Get the start application.
         *
         * @return      The app.
         */
        QString getStartApp() const;

        /**
         * @brief setStartApp. Set the start application.
         *
         * @param app     The app.
         */
        void setStartApp( QString app );

        /**
         * @brief getStartAppArgs. Get the start application arguments.
         *
         * @return      The arg.
         */
        QString getStartAppArgs() const;

        /**
         * @brief setStartAppArgs. Set the start application arguments.
         *
         * @param app     The args.
         */
        void setStartAppArgs( QString args );

        /**
         * @brief getCloseApp. Get the close application.
         *
         * @return      The app.
         */
        QString getCloseApp() const;

        /**
         * @brief setCloseApp. Set the close application.
         *
         * @param app     The app.
         */
        void setCloseApp( QString app );

        /**
         * @brief getCloseAppArgs. Get the close application arguments.
         *
         * @return      The args.
         */
        QString getCloseAppArgs() const;

        /**
         * @brief setCloseAppArgs. Set the close application arguments.
         *
         * @param args     The args.
         */
        void setCloseAppArgs( QString args );

        /**
         * @brief getDebug. Get the debug windows state.
         *
         * @return      The state.
         */
        bool getDebug() const;

        /**
         * @brief setDebug. Set the debug windows state.
         *
         * @param state     The state.
         */
        void setDebug( bool state );

        /**
         * @brief getVersion. Get the software version.
         *
         * @return      The version.
         */
        QString getVersion() const;

        /**
         * @brief getBuild. Get the git number of commits.
         *
         * @return      The number of commits.
         */
        QString getBuild() const;

        /**
         * @brief getHash. Get the git hash.
         *
         * @return      The hash.
         */
        QString getHash() const;

        /**
         * @brief getBuild. Get the git branch.
         *
         * @return      The branch.
         */
        QString getBranch() const;

    signals:

        /**
         * @brief signalConsole. Send a console message.
         *
         *  @param message      The message.
         */
        void    signalConsole( QString message );

        /**
         * @brief signalBrowserVersion. Signal the browser version.
         */
        void signalBrowserVersion();

        /**
         * @brief signalDefaultIconTypeChange. Signal a default icon type change.
         */
        void signalDefaultIconTypeChange();

        /**
         * @brief signalDefaultIconDataChange. Signal a default icon data change.
         */
        void signalDefaultIconDataChange();

        /**
         * @brief signalHideDefaultIconChange. Signal a hide default icon change.
         */
        void signalHideDefaultIconChange();

        /**
         * @brief signalIconTypeChange. Signal a icon type change.
         */
        void signalIconTypeChange();

        /**
         * @brief signalIconDataChange. Signal a icon data change.
         */
        void signalIconDataChange();

        /**
         * @brief signalShowNumberChange. Signal a show number state change.
         */
        void signalShowNumberChange();

        /**
         * @brief signalNumberColorChange. Signal a number color change.
         */
        void signalNumberColorChange();

        /**
         * @brief signalNumberSizeChange. Signal a number size change.
         */
        void signalNumberSizeChange();

        /**
         * @brief signalNumberAlignmmentChange. Signal a number alignment change.
         */
        void signalNumberAlignmentChange();

        /**
         * @brief signalNumberMarginsChange. Signal a number margins change.
         */
        void signalNumberMarginsChange();

        /**
         * @brief signalCountTypeChange. Signal a count type change.
         */
        void signalCountTypeChange();

        /**
         * @brief signalStartupDelayChange. Signal a startup delay change.
         */
        void signalStartupDelayChange();

        /**
         * @brief signalMinimizeTypeChange. Signal a minimize type change.
         */
        void signalMinimizeTypeChange();

        /**
         * @brief signalMinimizeIconTypeChange. Signal a minimize icon type change.
         */
        void signalMinimizeIconTypeChange();

        /**
         * @brief signalStartMinimizedChange. Signal a start minimized state change.
         */
        void signalStartMinimizedChange();

        /**
         * @brief signalRestoreWindowPositionsChange. Signal a restore window positions state change.
         */
        void signalRestoreWindowPositionsChange();

        /**
         * @brief signalCloseTypeChange. Signal a close type change.
         */
        void signalCloseTypeChange();

        /**
         * @brief signalDebugChange. Signal a debug state change.
         */
        void signalDebugChange();

        /**
         * @brief signalThemeChange. Signal a theme state change.
         */
        void signalThemeChange();

        /**
         * @brief signalStartAppChange. Signal a start application change.
         */
        void signalStartAppChange();

        /**
         * @brief signalStartAppArgsChange. Signal a start application arguments change.
         */
        void signalStartAppArgsChange();

        /**
         * @brief signalCloseAppChange. Signal a close application change.
         */
        void signalCloseAppChange();

        /**
         * @brief signalCloseAppArgsChange. Signal a close application arguments change.
         */
        void signalCloseAppArgsChange();

    private:

        /**
         * @brief m_app_pref_changed. Control for sending changes to the add-on.
         */
        bool m_app_pref_changed;

        /**
         * @brief m_platform_xx. Platform description.
         */
        QString m_platform_os;
        QString m_platform_arch;
        QString m_platform_nacl_arch;

        /**
         * @brief m_browser_xx. Browser description.
         */
        QString m_browser_name;
        QString m_browser_vendor;
        QString m_browser_version;
        QString m_browser_buildID;

        /**
         * @brief m_default_icon_type. Selected icon type.
         */
        DefaultIconType m_default_icon_type;

        /**
         * @brief m_default_icon_mime. Selected icon mime.
         */
        QString m_default_icon_mime;

        /**
         * @brief m_default_icon_data. Binary data icon image.
         */
        QByteArray m_default_icon_data;

        /**
         * @brief m_hide_default_icon. Hide default icon state.
         */
        bool    m_hide_default_icon;

        /**
         * @brief m_icon_type. Selected icon type.
         */
        IconType m_icon_type;

        /**
         * @brief m_icon_mime. Selected icon mime.
         */
        QString m_icon_mime;

        /**
         * @brief m_icon_data. Binary data icon image.
         */
        QByteArray m_icon_data;

        /**
         * @brief m_show_number. Show number in systray icon.
         */
        bool m_show_number;

        /**
         * @brief m_number_color. The color of the number in systray icon.
         */
        QString m_number_color;

        /**
         * @brief m_number_size. The size of the number in systray icon.
         */
        int m_number_size;

        /**
         * @brief m_number_alignment. Number alignment within the icon.
         */
        int m_number_alignment;

        /**
         * @brief m_number_margins. Margins for the number.
         */
        QMargins m_number_margins;

        /**
         * @brief m_count_type. Selected count type.
         */
        CountType m_count_type;

        /**
         * @brief m_startup_delay. The startup delay.
         */
        int m_startup_delay;

        /**
         * @brief m_minimize_type. Selected minimize type.
         */
        MinimizeType m_minimize_type;

        /**
         * @brief m_minimize_icon_type. Selected minimize icon type.
         */
        MinimizeIconType m_minimize_icon_type;

        /**
         * @brief m_start_minimized. Start TB minimized.
         */
        bool m_start_minimized;

        /**
         * @brief m_restore_window_positions. Force the same window positions on startup as recorded on the last hide.
         */
        bool m_restore_window_positions;

        /**
         * @brief m_close_type. Closing type for TB.
         */
        CloseType m_close_type;

        /**
         * @brief m_debug. Display debug window.
         */
        bool m_debug;

        /**
         * @brief m_version_major. Major version number.
         */
        QString m_version_major;

        /**
         * @brief m_version_minor. Minor version number.
         */
        QString m_version_minor;

        /**
         * @brief m_version_patch. patch version number.
         */
        QString m_version_patch;

        /**
         * @brief m_version_build. Git commits count.
         */
        QString m_version_build;

        /**
         * @brief m_version_build. Git hash.
         */
        QString m_version_hash;

        /**
         * @brief m_version_build. Git branch.
         */
        QString m_version_branch;

        /**
         * @brief m_theme. The theme.
         */
        Theme m_theme;

        /**
         * @brief m_start_app
         */
        QString m_start_app;

        /**
         * @brief m_start_app_args
         */
        QString m_start_app_args;

        /**
         * @brief m_close_app
         */
        QString m_close_app;

        /**
         * @brief m_close_app_args
         */
        QString m_close_app_args;
};

#endif // PREFERENCES_H
