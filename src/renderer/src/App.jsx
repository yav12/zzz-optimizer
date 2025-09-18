import { BrowserRouter, Routes, Route, NavLink } from 'react-router-dom'

import About from './components/about'
import Library from './library/library'
import FilePicker from './fpicker'

function App() {
  // state for disks
  return (
    <>
      {/* new navigation bar */}
      <BrowserRouter>
        <nav className="navigation">
          <NavLink to="/">Home</NavLink>
          <NavLink to="/library">Library</NavLink>
          <NavLink to="/file-picker">import</NavLink>
        </nav>
        <Routes>
          <Route path="/" element={<div>Home Page</div>} />
          <Route path="/library" element={<Library />} />
          <Route path="/file-picker" element={<FilePicker />} />
        </Routes>
      </BrowserRouter>

      {/* stuff to be deleted */}
      {/* <div className="actions">
        <div className="action">
          <a href="https://electron-vite.org/" target="_blank" rel="noreferrer">
            Documentation
          </a>
        </div>
        <div className="action">
          <a target="_blank" rel="noreferrer" onClick={ipcHandle}>
            Send IPC
          </a>
        </div>
      </div> */}

      {/* footer component */}
      <About />
    </>
  )
}

export default App
