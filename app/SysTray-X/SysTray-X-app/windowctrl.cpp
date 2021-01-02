#include "windowctrl.h"

/*
 *  Qt includes
 */
#include <QWidget>
#include <QWindow>
#include <QCoreApplication>

/*
 *  System includes
 */

/*
 *  Local includes
 */
#include "debug.h"
#include "preferences.h"

/*
 *  Constructor
 */
WindowCtrl::WindowCtrl( Preferences* pref, QObject *parent )
#ifdef Q_OS_UNIX
    : WindowCtrlUnix( parent )
#elif defined Q_OS_WIN
    : WindowCtrlWin( parent )
#else
    : public QObject
#endif
{
    /*
     *  Store preferences
     */
    m_pref = pref;

    /*
     *  Initialize
     */
    setMinimizeType( m_pref->getMinimizeType() );

    /*
     *  Get pids
     */
    m_pid = QCoreApplication::applicationPid();
    m_ppid = getPpid();

    /*
     *  Get the TB windows
     */
    findWindows( m_ppid );
}


/*
 *  Is thunderbird our parent?
 */
bool    WindowCtrl::thunderbirdStart() const
{
   return isThunderbird( getPpid() );
}


/*
 *  Test func 1
 */
void    WindowCtrl::slotWindowTest1()
{
    emit signalConsole("Test 1 started");

    // Do something.

//    signalHideDefaultIconChange( true );

//    emit signalShow();

//    emit signalConsole( QString( "Found Ppid: %1" ).arg( getPpid() ) );
//    emit signalConsole( QString( "Found XID: %1" ).arg( getWinId() ) );

//    findWindow( "- Mozilla Thunderbird" );
    displayWindowElements( "- Mozilla Thunderbird" );
//    findWindow( 4313 );
//    displayWindowElements( getWinId() );

//    findWindows( m_ppid );

    emit signalConsole("Test 1 done");
}


/*
 *  Test func 2
 */
void    WindowCtrl::slotWindowTest2()
{
    emit signalConsole("Test 2 started");

    // Do something.

//    signalHideDefaultIconChange( false );

//    emit signalHide();

//    hideWindow( getWinId(), true );

//    findWindow( m_ppid );
//    emit signalConsole( QString( "Hwnd ppid: %1" ).arg( getWinIds()[0] ) );

    emit signalConsole("Test 2 done");
}


/*
 *  Test func 3
 */
void    WindowCtrl::slotWindowTest3()
{
    emit signalConsole("Test 3 started");

    // Do something.
//    hideWindow( getWinId(), false );

//    emit signalConsole( QString( "Pid %1" ).arg( m_pid ) );
//    emit signalConsole( QString( "Ppid %1" ).arg( m_ppid ) );

    emit signalConsole("Test 3 done");
}


/*
 *  Handle change in minimize type change
 */
void    WindowCtrl::slotMinimizeTypeChange()
{
    setMinimizeType( m_pref->getMinimizeType() );
}


/*
 *  Handle change in start minimized state
 */
void    WindowCtrl::slotStartMinimizedChange()
{
    m_start_minimized = m_pref->getStartMinimized();
}


/*
 *  Handle change in window state
 */
void    WindowCtrl::slotWindowState( Preferences::WindowState state )
{
#ifdef DEBUG_DISPLAY_ACTIONS
    emit signalConsole( QString( "State change to: %1" ).arg( Preferences::WindowStateString.at( state ) ) );
#endif

#ifdef Q_OS_UNIX

    /*
     *  Update the TB windows and states
     */
    findWindows( m_ppid );

    QList< quint64 > win_ids = getWinIds();
    QList< Preferences::WindowState >    win_states = getWindowStates();

    /*
     *  Minimize all?
     */
    if( state == Preferences::STATE_MINIMIZED_ALL || state == Preferences::STATE_MINIMIZED_ALL_STARTUP )
    {
#ifdef DEBUG_DISPLAY_ACTIONS
        emit signalConsole( QString( "Minimize all" ) );
#endif

        if( state == Preferences::STATE_MINIMIZED_ALL )
        {
            updatePositions();
        }

        /*
         *   Close pressed on one of the windows, minimize them all
         */
        for( int i = 0 ; i < win_ids.length() ; ++i )
        {
#ifdef DEBUG_DISPLAY_ACTIONS
            emit signalConsole( QString( "Window state: %1, %2" )
                                .arg( win_ids.at( i ) )
                                .arg( Preferences::WindowStateString.at( win_states.at( i ) ) ) );
#endif

            if( ( win_states.at( i ) != Preferences::STATE_MINIMIZED && getMinimizeType() == Preferences::PREF_DEFAULT_MINIMIZE ) ||
                ( win_states.at( i ) != Preferences::STATE_DOCKED && getMinimizeType() != Preferences::PREF_DEFAULT_MINIMIZE ) )
            {
                minimizeWindow( win_ids.at( i ), getMinimizeType() != Preferences::PREF_DEFAULT_MINIMIZE );
            }
        }
    }
    else
    {
        for( int i = 0 ; i < win_ids.length() ; ++i )
        {
#ifdef DEBUG_DISPLAY_ACTIONS
            emit signalConsole( QString( "Window state: %1, %2" )
                                .arg( win_ids.at( i ) )
                                .arg( Preferences::WindowStateString.at( win_states.at( i ) ) ) );
#endif

            if( ( win_states.at( i ) == Preferences::STATE_MINIMIZED && getMinimizeType() != Preferences::PREF_DEFAULT_MINIMIZE ) )
            {
                minimizeWindow( win_ids.at( i ), true );
            }
        }
    }

#else

    /*
     *  Update the TB windows and states
     */
    findWindows( m_ppid );

    /*
     *  Minimize all?
     */
    if( state == Preferences::STATE_MINIMIZED_ALL || state == Preferences::STATE_MINIMIZED_ALL_STARTUP )
    {
//        emit signalConsole( QString( "Minimize all" ) );

        QList< quint64 > win_ids = getWinIds();

        /*
         *   Close pressed on one of the windows, minimize them all
         */
        for( int i = 0 ; i < win_ids.length() ; ++i )
        {
            minimizeWindow( win_ids.at( i ), getMinimizeType() );
        }
    }

#endif

#ifdef DEBUG_DISPLAY_ACTIONS
    emit signalConsole( "State change done" );
#endif
}


/*
 *  Handle show / hide signal
 */
void    WindowCtrl::slotShowHide()
{
#ifdef DEBUG_DISPLAY_ACTIONS
    emit signalConsole( "Show/Hide" );
#endif

    /*
     *  Update the TB windows
     */
    findWindows( m_ppid );

    /*
     *  Get the window ids
     */
    QList< quint64 > win_ids = getWinIds();
    QList< Preferences::WindowState >    win_states = getWindowStates();

    for( int i = 0 ; i < win_ids.length() ; ++i )
    {
#ifdef Q_OS_UNIX

        updatePositions();

#endif

        if( win_states.at( i ) == Preferences::STATE_MINIMIZED || win_states.at( i ) == Preferences::STATE_DOCKED )
        {
            normalizeWindow( win_ids.at( i ) );
        }
        else
        {
            minimizeWindow( win_ids.at( i ), getMinimizeType() != Preferences::PREF_DEFAULT_MINIMIZE );
        }
    }
}


/*
 *  Handle close signal
 */
void    WindowCtrl::slotClose()
{
#ifdef DEBUG_DISPLAY_ACTIONS
    emit signalConsole( "Close" );
#endif

    /*
     *  Update the TB windows
     */
    findWindows( m_ppid );

    /*
     *  Get the window ids
     */
    QList< quint64 > win_ids = getWinIds();

    /*
     *  Delete all
     */
    for( int i = 0 ; i < win_ids.count() ; ++i )
    {
        deleteWindow( win_ids.at( i ) );
    }
}


/*
 *  Handle the startup window posiions.
 */
void    WindowCtrl::slotPositions( QList< QPoint > window_positions )
{
#ifdef Q_OS_UNIX

    setPositions( window_positions );

#endif
}