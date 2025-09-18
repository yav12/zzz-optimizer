// import Disc from './Disc'
import { use, useEffect, useRef } from 'react'
import { DiscContext } from './DiscContext'

function LibraryContainer() {
  useEffect(() => {
    // fetch library data here
  }, [])
  return (
    <div className="library-container">
      <></>
    </div>
  )
}

function Library() {
  return (
    <div>
      <h1>Library Page</h1>
      <p>disk library not yet implemented...</p>
      <LibraryContainer />
    </div>
  )
}

export default Library
