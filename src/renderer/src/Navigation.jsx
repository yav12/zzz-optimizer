import { BrowserRouter, Routes, Route, NavLink } from 'react-router-dom'
import Library from './library'
import FilePicker from './FilePicker'

function Navigation() {
  return (
    <BrowserRouter>
      <nav className="navigation">
        <NavLink to="/">Home</NavLink>
        <NavLink to="/library">Library</NavLink>
        <NavLink to="/file-picker">File Picker</NavLink>
      </nav>
      <Routes>
        <Route path="/" element={<div>Home Page</div>} />
        <Route path="/library" element={<Library />} />
        <Route path="/file-picker" element={<FilePicker />} />
      </Routes>
    </BrowserRouter>
  )
}

export default Navigation
