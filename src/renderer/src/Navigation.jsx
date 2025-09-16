import { BrowserRouter, Routes, Route, NavLink } from 'react-router-dom'
import Library from './library'

function Navigation() {
  return (
    <BrowserRouter>
      <nav className="navigation">
        <NavLink to="/">Home</NavLink>
        <NavLink to="/library">Library</NavLink>
      </nav>
      <Routes>
        <Route path="/" element={<div>Home Page</div>} />
        <Route path="/library" element={<Library />} />
      </Routes>
    </BrowserRouter>
  )
}

export default Navigation
