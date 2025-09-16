import Disc from './library/disc'
import { useFilePicker } from 'use-file-picker'

function Library() {
  // const [openFileSelector, { filesContent, loading, errors }] = useFilePicker({
  //   accept: '.json',
  //   multiple: false,
  //   readAs: 'Text'
  // })

  // console.log(filesContent, loading, errors)

  return (
    <div>
      <h1>Library Page</h1>
      <p>This is the library page content.</p>

      {/* <button onClick={openFileSelector}>Import from File</button>

      {filesContent.map((file, index) => (
        <div key={index}>
          <h2>{file.name}</h2>export
          <div key={index}>{file.content}</div>
          <br />
        </div>
      ))} */}
    </div>
  )
}

export default Library
