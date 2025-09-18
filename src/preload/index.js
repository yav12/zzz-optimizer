import { contextBridge } from 'electron'
import { electronAPI } from '@electron-toolkit/preload'

// Custom APIs for renderer
const api = {
  readFile: (filePath) => {
    try {
      const fs = require('fs')
      return fs.readFileSync(filePath, 'utf-8')
    } catch (e) {
      console.error(`Error reading file at ${filePath}:`, e)
      return null
    }
  },

  saveFile: (filePath, content) => {
    try {
      const fs = require('fs')
      fs.writeFileSync(filePath, content, 'utf-8')
      return true
    } catch (e) {
      console.error(`Error writing file at ${filePath}:`, e)
      return false
    }
  }
}

// Use `contextBridge` APIs to expose Electron APIs to
// renderer only if context isolation is enabled, otherwise
// just add to the DOM global.
if (process.contextIsolated) {
  try {
    contextBridge.exposeInMainWorld('electron', electronAPI)
    contextBridge.exposeInMainWorld('api', api)
  } catch (error) {
    console.error(error)
  }
} else {
  window.electron = electronAPI
  window.api = api
}
