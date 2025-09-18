import { useFilePicker } from 'use-file-picker'
import { useRef } from 'react'

function FilePicker() {
  const { openFilePicker, filesContent, loading } = useFilePicker({
    accept: '.json',
    multiple: false,
    readAs: 'text'
  })

  if (loading) {
    return <div>Loading...</div>
  }

  return (
    <div>
      <a className="button" onClick={() => openFilePicker()}>
        Select file
      </a>
      {filesContent.map((file, index) => (
        <div key={index}>
          <h2>{file.name}</h2>
          <div className="file-content" key={index}>
            {file.content}
          </div>
        </div>
      ))}
    </div>
  )
}

export default FilePicker
